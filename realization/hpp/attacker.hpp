

#ifndef AUTHENTICATION_PROTOCOL_ATTACKER_HPP
#define AUTHENTICATION_PROTOCOL_ATTACKER_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"
#include "../cpp/client.cpp"
#include "client.hpp"

//!   \brief Класс Attacker показывает демонстрацию атаки возпроизведения
//!   Каждый метод класса забирает из последнего сеанса соответсвующие данные  и отправляет их серверу.
class Attacker : public Client {
public:
    Attacker() = default;

    std::vector<Point> client_gives_initial_points() override;

    Point clients_point() override;

    S_time clients_summation(mpz_class binary_string) override;
};

#endif //AUTHENTICATION_PROTOCOL_ATTACKER_HPP
