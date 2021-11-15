
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

class Client {
public:
    Client();

    //шаг 4
    std::vector<Point> client_gives_initial_points();

    //шаг 5
    Point clients_point();

    //шаг 6
    mpz_class clients_summation(mpz_class binary_string);


private:
    int m;
    std::vector<mpz_class> xi;
    mpz_class k; // рандом

    //шаг 2
    void choose_xi();

    //шаг 3
    void generate_k();

    //шаг 6.5
    mpz_class sum(mpz_class &bit_string);

};

Client::Client() {
    int i;
    std::cout << "choose curve\n";
    std::cout << "1.singular curve\n";
    std::cout << "2.seck256k1\n";
    std::cin >> i;
    curve.choose_curve(i);

    //шаг 1
    std::cout << "write how many x do you have\n";
    std::cin >> m;
    std::cout << "\n";
    //шаг 2
    choose_xi();
    //шаг 3
    generate_k();
}

void Client::choose_xi() {
    //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
    std::cout << "write x[i]\n";
    for (int i = 0; i < m; ++i) {
        mpz_class current;
        std::cin >> current;
        xi.push_back(current);
    }
}

void Client::generate_k() {
    //Доказывающий A генерирует случайное целое число k,
    //где 1≤k≤ q−2,
//       mpz_random(k.get_mpz_t(), reinterpret_cast<mp_size_t>
//                                  (curve.find_biggest_prime_divisor().get_mpz_t()) - 2);
    srand(time(nullptr));
    k = rand();
}

std::vector<Point> Client::client_gives_initial_points() {

    std::vector<Point> Y(m);
    for (int i = 0; i < m; ++i) {
        ////и вычисляет значения Yi =[−xi ]G, i=1,, m.
        mpz_class mult = (-xi[i]) + p;
        Y[i] = curve.get_G() * mult;
    }
    return Y;
}

Point Client::clients_point() {
    // вычисляет R=[k]G и отправляет проверяющему B
    // точку эллиптической кривой R.
    Point R;
    R = curve.get_G() * k;
    return R;
}

mpz_class Client::clients_summation(mpz_class binary_string) {
    mpz_class s;
    mpz_class q = curve.find_biggest_prime_divisor();

    s = (k + sum(binary_string)) % q;
    if (s < 0) { s += q; }
    return s;
}

mpz_class Client::sum(mpz_class &bit_string) {
    //xi с ai из bit string
    mpz_class result = 0;
    int i = 0;
    while (bit_string) {
        result += (bit_string % 10) * xi[m - 1 - i];
        ++i;
        bit_string /= 10;
    }
    return result;
}

#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
