#pragma once
#include <string>
#include <vector>
#include <tuple> 

using ip_t = decltype(std::make_tuple(0, 0, 0, 0));

std::vector<std::string> split(const std::string &str, char d);
ip_t parse_ip(const std::string &text); 

std::string to_string(const ip_t &ip);