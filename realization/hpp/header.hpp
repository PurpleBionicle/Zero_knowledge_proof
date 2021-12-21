
#ifndef AUTHENTICATION_PROTOCOL_HEADER_HPP
#define AUTHENTICATION_PROTOCOL_HEADER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdio>
#include <exception>
#include <random>
#include <fstream>
#include <cmath>
#include <chrono>
#include <gmpxx.h>
#include "nlohmann/json.hpp"

std::fstream file("Public_keys.txt");
mpz_class a = 0;
mpz_class p("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 16);
using json = nlohmann::json;
std::fstream file_log("../Logging.jsonl", std::ios::app);

#endif //AUTHENTICATION_PROTOCOL_HEADER_HPP
