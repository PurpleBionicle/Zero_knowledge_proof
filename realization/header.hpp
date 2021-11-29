
#ifndef AUTHENTICATION_PROTOCOL_HEADER_HPP
#define AUTHENTICATION_PROTOCOL_HEADER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <exception>
#include <random>
#include <fstream>
#include <gmpxx.h>

std::fstream file("Public_keys.txt");
mpz_class a = 0;// коэффициент кривой
mpz_class p("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 16);
std::fstream file_log("Logging.txt", std::ios::app);

#endif //AUTHENTICATION_PROTOCOL_HEADER_HPP
