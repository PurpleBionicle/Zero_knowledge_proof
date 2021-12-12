

int choose_mode() {
    int n;
    std::cout << "choose mode:\n";
    std::cout << "1.prover\n";
    std::cout << "2.attacker\n";
    std::cin >> n;
    return n;
}

bool check_time(std::chrono::time_point<std::chrono::system_clock> time) {
    const auto now = std::chrono::system_clock::now();
    std::chrono::duration<float> difference = now-time;
    return difference.count()<10;
}

Point sum(mpz_class bit_string, const std::vector<Point> &Y) {
    Point result(0, 0);
    int i = 0;
    while (bit_string) {
        Point current = Y[Y.size() - 1 - i] * (bit_string % 10);
        result += current;
        ++i;
        bit_string /= 10;
    }
    return result;
}

mpz_class generate_binary_string(const size_t &Y_size) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(
            0, std::numeric_limits<int>::max());

    int random = dist6(rng);
    mpz_class bit_string = 0;
    while (!bit_string) {
        bit_string = random % static_cast<int>(pow(2, Y_size)); //длины m
    }
    return bit_string;
}

bool check_equality(const Point &R, const mpz_class &s,
                    const std::vector<Point> &Y, mpz_class &binary) {
    Point sG = curve.get_G() * s;
    Point d = sum(binary, Y) + sG;
    bool flag = false;
    for (size_t i = 0; i < d.x.get_str(2).length(); ++i) {
        flag |= d.x.get_str(2)[i] ^ R.x.get_str(2)[i];
    }

    for (size_t j = 0; j < d.y.get_str(2).length(); ++j) {
        flag |= d.y.get_str(2)[j] ^ R.y.get_str(2)[j];
    }
    return !flag;
}

void server() {

    int n = choose_mode();
    Client *A = nullptr;
    if (n == 1) { A = new Client; }
    else if (n == 2) {
        A = new Attacker;
    } else {
        std::cerr << "Wrong input";
    }

    std::vector<Point> Y;
    Y = A->client_gives_initial_points();

    Point R = A->clients_point();

    mpz_class bit_string = generate_binary_string(Y.size());
    mpz_class binary = two_notation(bit_string);
    S_time current_session;
    current_session = A->clients_summation(binary);
    crossover_time_string(binary, current_session.time);

    if (check_time(current_session.time)) {
        if (check_equality(R, current_session.s, Y, binary)) {
            std::cout << "\nTHE PROOF IS ACCEPTED";
            log(true, "", n);
        } else {
            log(false, "wrong answer for challenge ", n);
            std::cout << "DENIED";
        }
    } else{
        log(false, "wrong time", n);
        std::cout << "DENIED";
    }
    delete A;
}

