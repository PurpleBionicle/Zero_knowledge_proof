#include "../hpp/attacker.hpp"

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

S_time Attacker::clients_summation(mpz_class binary_string) {
    mpz_class s;
    S_time current;
    file >> current.s;
    int time_=0;
    file>>time_;
    current.time +=std::chrono::milliseconds(time_);
    return current;
}
