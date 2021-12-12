#include "../hpp/client.hpp"
#include "point.cpp"

Client::Client() {
    int i = 0;
    std::cout << "choose curve:\n";
    std::cout << "1.singular curve\n";
    std::cout << "2.seck256k1\n";
    std::cin >> i;
    curve.choose_curve(i);

    std::cout << "write how many x do you have\n";
    std::cin >> m;
    choose_xi();
    generate_k();
}

void Client::choose_xi() {
    std::cout << "write x[i]\n";
    for (int i = 0; i < m; ++i) {
        mpz_class current;
        std::cin >> current;
        xi.push_back(current);
    }
}

void Client::generate_k() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(
            0, std::numeric_limits<int64_t>::max());
    k = dist6(rng);
}

std::vector<Point> Client::client_gives_initial_points() {

    std::vector<Point> Y(m);
    for (int i = 0; i < m; ++i) {
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
    Point R;
    R = curve.get_G() * k;
    file << "0" << "\n" << R.x << "\n";
    file << R.y << "\n";
    return R;
}

mpz_class Client::clients_summation(mpz_class &binary_string) {
    mpz_class s;
    mpz_class q = curve.find_biggest_prime_divisor();

    s = k + (sum(binary_string)) % q;
    while (s < 0) { s += q; }
    file << s << "\n";
    file.close();
    return s;
}

mpz_class Client::sum(mpz_class &bit_string) {
    mpz_class result = 0;
    int i = 0;
    while (bit_string) {
        result += (bit_string % 10) * xi[m - 1 - i];
        ++i;
        bit_string /= 10;
    }
    return result;
}
