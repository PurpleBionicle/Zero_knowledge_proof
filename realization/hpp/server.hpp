
#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP

#include "header.hpp"
#include "point.hpp"
#include "client.hpp"
#include "curve.hpp"
#include "logging.hpp"
#include "attacker.hpp"
#include "../cpp/attacker.cpp"

//! \brief Выбор режима - атака / доказующий
int choose_mode();

//! \brief выполняет суммирование точек кривой ,сопряженные с challenge
Point sum(mpz_class bit_string, const std::vector<Point> &Y);

//! \brief генерация challenge-а - бинарной строки длины m(кол-во закрытых ключей)
mpz_class generate_binary_string(const size_t &Y_size);

//! \brief выболняет сравнение результатов доказывающего
bool check_equality(const Point &R, const mpz_class &s,
                    const std::vector<Point> &Y, mpz_class &binary);

//! \brief Функция вызывающая функции, выполняющие раунды протокола - методы класса Client / Attacker
void server();

#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
