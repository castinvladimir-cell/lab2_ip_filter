#include "lib.h"
#include <sstream>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

ip_t parse_ip(const std::string &text)
{
    auto parts =  split(text, '.');
    return std::make_tuple(std::stoi(parts.at(0)), std::stoi(parts.at(1)), std::stoi(parts.at(2)), std::stoi(parts.at(3)));
}

std::string to_string(const ip_t &ip)
{
    std::ostringstream out;
    out << std::get<0>(ip) << "." << std::get<1>(ip) << "."
        << std::get<2>(ip) << "." << std::get<3>(ip);
    return out.str();
}