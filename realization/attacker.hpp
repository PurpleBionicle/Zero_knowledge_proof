

#ifndef AUTHENTICATION_PROTOCOL_ATTACKER_HPP
#define AUTHENTICATION_PROTOCOL_ATTACKER_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"
#include "client.hpp"

class Attacker : public Client {
public:
    Attacker() = default;

    std::vector<Point> client_gives_initial_points() override;

    Point clients_point() override;

    mpz_class clients_summation(mpz_class
                                binary_string) override;
};

std::vector<Point> Attacker::client_gives_initial_points() {
    std::vector<Point> Y;
    while (true) {
        mpz_class coordinate_x;
        mpz_class coordinate_y;
        std::string str;
        file >> str;
        if (str != "0") {
            mpz_set_str(coordinate_x.get_mpz_t(), &str[0], 10);
            file >> coordinate_y;
            Point current(coordinate_x, coordinate_y);
            Y.push_back(current);
        } else {
            break;
        }
    }
    return Y;
}

Point Attacker::clients_point() {
    mpz_class coordinate_x;
    mpz_class coordinate_y;
    file >> coordinate_x;
    file >> coordinate_y;
    Point current(coordinate_x, coordinate_y);
    return current;
}

mpz_class Attacker::clients_summation(mpz_class
                                      binary_string) {
    mpz_class s;
    file >> s;
    return s;
}


#endif //AUTHENTICATION_PROTOCOL_ATTACKER_HPP
