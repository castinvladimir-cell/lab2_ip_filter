#define BOOST_TEST_MODULE test_ip_filter

#include "lib.h"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_ip_filter)

BOOST_AUTO_TEST_CASE(test_split)
{
    BOOST_CHECK(split("11.22.33.44", '.').size() == 4);
    BOOST_CHECK(split("11.22.33.44", '.').at(0) == "11");
    BOOST_CHECK(split("11.22.33.44", '.').at(3) == "44");
}

BOOST_AUTO_TEST_CASE(test_parse_ip)
{
    BOOST_CHECK(parse_ip("1.2.3.4") == std::make_tuple(1, 2, 3, 4));
    BOOST_CHECK(parse_ip("192.168.0.255") == std::make_tuple(192, 168, 0 ,255));
}

BOOST_AUTO_TEST_CASE(test_to_string)
{
    BOOST_CHECK(to_string(std::make_tuple(1, 2, 3, 4)) == "1.2.3.4");
    BOOST_CHECK(to_string(parse_ip("46.70.29.76")) == "46.70.29.76");
}

BOOST_AUTO_TEST_SUITE_END()