#include "point.cpp"

void crossover_time_string(mpz_class &binary_string,
                           std::chrono::time_point<std::chrono::system_clock> p1) {

    std::string m = binary_string.get_str();
    mpz_class timestamp = std::chrono::duration_cast<std::chrono::seconds>(
            p1.time_since_epoch()).count();
    auto mod_timestamp = timestamp % pow(2, m.length());
    auto bin_timestamp = two_notation(mod_timestamp);
    auto bin_buffer = binary_string;
    binary_string = 0;
    for (int i = 0; i < m.length(); ++i) {
        int time_ = static_cast<int>(bin_timestamp.get_str()[i] - '0');
        int string_ = static_cast<int>(bin_buffer.get_str()[i] - '0');
        if (time_ < 0) { time_ = 0; }
        int current_mod = time_ ^ string_;
        binary_string += current_mod * pow(10, i);
    }

}

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
    for (const auto &i: Y) {
        file << i.x << "\n";
        file << i.y << "\n";
    }
    return Y;
}

Point Client::clients_point() {
    Point R;
    R = curve.get_G() * k;
    file << "0\n" << R.x << "\n";
    file << R.y << "\n";
    return R;
}

S_time Client::clients_summation(mpz_class binary_string) {
    mpz_class s;
    S_time S_time;
    mpz_class q = curve.find_biggest_prime_divisor();
    const auto p1 = std::chrono::system_clock::now();
    crossover_time_string(binary_string, p1);
    S_time.time = p1;
    S_time.s = k + (sum(binary_string)) % q;
    while (S_time.s < 0) { S_time.s += q; }
    file << S_time.s << "\n";
    file << S_time.time.time_since_epoch().count() << "\n";
    file.close();
    return S_time;
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
