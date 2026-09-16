cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

find_package(Boost REQUIRED)

add_library(ip_lib lib.cpp)
add_executable(ip_filter_cli ip_filter.cpp)
add_executable(test_ip_filter test_ip_filter.cpp)

set_target_properties(ip_lib ip_filter_cli test_ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(test_ip_filter PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(ip_filter_cli PRIVATE ip_lib)
target_link_libraries(test_ip_filter PRIVATE ip_lib)

if (MSVC)
    target_compile_options(ip_lib PRIVATE /W4)
    target_compile_options(ip_filter_cli PRIVATE /W4)
    target_compile_options(test_ip_filter PRIVATE /W4)
else ()
    target_compile_options(ip_lib PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(ip_filter_cli PRIVATE -Wall -Wextra -pedantic)
endif()

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

if(APPLE)
    set(CPACK_GENERATOR TGZ)
else()
    set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_test(test_ip_filter test_ip_filter)
