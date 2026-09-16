#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#include "lib.h"

int main(int, char const *[])
{
    try
    {
        std::vector<ip_t> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(parse_ip(v.at(0)));
        }

        std::sort(ip_pool.begin(), ip_pool.end(), [](const auto &a, const auto &b) { return a > b; });

        // Печать адреса
        auto print_ip = [](const auto &ip)
        {
            std::cout << to_string(ip) << std::endl;
        };

        // Список 1 (все адреса)
        for (const auto &ip : ip_pool)
        {
            print_ip(ip);
        }

        // Список 2 (первый байт = 1)
        for (const auto &ip : ip_pool)
        {
            if (std::get<0>(ip) == 1)
            {
                print_ip(ip);
            }
        }

        // Список 3 (первый байт = 46 и второй = 70)
        for (const auto &ip : ip_pool)
        {
            if (std::get<0>(ip) == 46 && std::get<1>(ip) == 70)
            {
                print_ip(ip);
            }
        }

        // Список 4 (любой байт = 46)
        for (const auto &ip : ip_pool)
        {
            if (std::get<0>(ip) == 46 || std::get<1>(ip) == 46
             || std::get<2>(ip) == 46 || std::get<3>(ip) == 46)
            {
                print_ip(ip);
            }
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}