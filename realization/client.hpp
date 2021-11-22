
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"


class Client {
public:
    Client();

    virtual //шаг 8
    std::vector<Point> client_gives_initial_points();

    virtual //шаг 9
    Point clients_point();

    virtual //шаг 12
    mpz_class clients_summation(mpz_class binary_string);

private:
    int m;
    std::vector<mpz_class> xi;
    mpz_class k; // рандом

    //шаг 6
    void choose_xi();

    //шаг 7
    void generate_k();

    //шаг 12.5
    mpz_class sum(mpz_class &bit_string);

};

Client::Client() {
    int i;
    std::cout << "choose curve:\n";
    std::cout << "1.singular curve\n";
    std::cout << "2.seck256k1\n";
    std::cin >> i;
    //шаг 2-3
    curve.choose_curve(i);

    //шаг 5
    std::cout << "write how many x do you have\n";
    std::cin >> m;
    //шаг 6
    choose_xi();
    //шаг 7
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
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(
            0, std::numeric_limits<int64_t>::max());
    k = dist6(rng);
}

std::vector<Point> Client::client_gives_initial_points() {

    std::vector<Point> Y(m);
    for (int i = 0; i < m; ++i) {
        ////и вычисляет значения Yi =[−xi ]G, i=1,, m.
        mpz_class mult = (-xi[i]) % curve.get_order();
        while (mult < 0) {
            mult += curve.get_order();
        }
        Y[i] = curve.get_G() * mult;
    }
    for (auto &i: Y) {
        file << i.x << "\n";
        file << i.y << "\n";
    }
    return Y;
}

Point Client::clients_point() {
    // вычисляет R=[k]G и отправляет проверяющему B
    // точку эллиптической кривой R.
    Point R;
    R = curve.get_G() * k;
    file << "0" << "\n" << R.x << "\n";
    file << R.y << "\n";
    return R;
}

mpz_class Client::clients_summation(mpz_class binary_string) {
    mpz_class s;
    mpz_class q = curve.find_biggest_prime_divisor();

    s = k + (sum(binary_string)) % q;
    while (s < 0) { s += q; }
    file << s << "\n";
    file.close();
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
