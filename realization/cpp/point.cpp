
mpz_class two_notation(mpz_class num) {
    mpz_class result = 0, k = 1;

    while (num) {
        result += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return result;
}

Point Point::operator=(const Point &B) {
    this->y = B.y;
    this->x = B.x;
    return *this;
}

Point Point::operator+(const Point &B) const {
    Point A;
    mpz_class alfa;
    mpz_class inverse = 0;
    if (B.x == 0 && B.y == 0) {
        A.y = this->y;
        A.x = this->x;
        return A;
    }
    if (this->x == 0 && this->y == 0) {
        A.y = B.y;
        A.x = B.x;
        return A;
    }

    if (this->x == B.x && this->y == -B.y) {
        A.x = 0;
        A.y = 0;
        return A;
    }
    if (*this == B) {
        mpz_class double_y = 2 * B.y;
        mpz_invert(inverse.get_mpz_t(), double_y.get_mpz_t(), p.get_mpz_t());
        alfa = ((3 * B.x * B.x + a) * inverse) % p;
    } else {
        mpz_class diff = this->x - B.x;
        mpz_invert(inverse.get_mpz_t(), diff.get_mpz_t(), p.get_mpz_t());
        alfa = ((this->y - B.y) * inverse) % p;
    }
    if (alfa == 0) {
        A.x = 0;
        A.y = 0;
        return A;
    }

    A.x = (alfa * alfa - this->x - B.x) % p;
    A.y = (alfa * (A.x - this->x) + this->y) % p;
    A.y *= -1;
    while (A.x < 0) A.x += p;
    while (A.y < 0) A.y += p;
    return A;
}

Point Point::operator+=(Point &B) {
    mpz_class alfa;
    mpz_class inverse;
    if (B.x == 0 && B.y == 0) return *this;
    if (this->x == 0 && this->y == 0) {
        this->y = B.y;
        this->x = B.x;
        return *this;
    }

    if (this->x == B.x && this->y == -B.y) {
        this->x = 0;
        this->y = 0;
        return *this;
    }
    if (*this == B) {
        mpz_class double_y = 2 * B.y;
        mpz_invert(inverse.get_mpz_t(), double_y.get_mpz_t(), p.get_mpz_t());
        alfa = ((3 * B.x * B.x + a) * inverse) % p;
    } else {
        mpz_class diff = this->x - B.x;
        mpz_invert(inverse.get_mpz_t(), diff.get_mpz_t(), p.get_mpz_t());
        alfa = ((this->y - B.y) * inverse) % p;
    }
    if (alfa == 0) {
        this->x = 0;
        this->y = 0;
        return *this;
    }

    mpz_class xx = this->x;
    mpz_class yy = this->y;
    this->x = (alfa * alfa - this->x - B.x) % p;
    this->y = (alfa * (this->x - xx) + yy) % p;
    while (this->x < 0) this->x += p;
    this->y *= -1;
    while (this->y < 0) this->y += p;
    return *this;
}

Point Point::operator*(const mpz_class &k) const {
    if (k == 0) { return {0, 0}; }
    mpz_class k2 = two_notation(k);

    Point Y;
    std::vector<Point> templ;
    templ.push_back(*this);

    int i = 1;
    mpz_class k_2 = k2;
    k_2 /= 10;
    while (k_2) {
        Y = templ[i - 1] + templ[i - 1];
        templ.push_back(Y);
        k_2 /= 10;
        ++i;
    }

    Point result;
    bool init = false;
    for (auto &j: templ) {
        if (k2 % 10 != 0) {
            if (!init) {
                result = j;
                init = true;
            } else {
                result += j;
            }
        }
        k2 /= 10;
    }
    return result;
}
