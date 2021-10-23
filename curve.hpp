

#ifndef AUTHENTICATION_PROTOCOL_CURVE_HPP
#define AUTHENTICATION_PROTOCOL_CURVE_HPP

#include "header.hpp"
#include "point.hpp"


class Curve {
    //elliptical curve y^2=x^3+ax+b
    //Secp256k1
private:
    mpz_class p; // Zp
    point G;//базовая точка
    mpz_class order;
    mpz_class a, b; // коэффициенты кривой
    int kofactor = 1;

    void set_order() {
        mpz_class order1("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
        order = order1;
    }

    void set_p() {
        mpz_class p1("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
        p = p1;
    }

    void set_koef_of_curve() {
        mpz_class a1("00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000", 16);
        a = a1;
        mpz_class b1("00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000007", 16);
        b = b1;
    }

    void set_G() {
        mpz_class x1("79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 16);
        G.x = x1;
        mpz_class y1("483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 16);
        G.y = y1;
    }

public:
    Curve() {
        set_order();
        set_p();
        set_koef_of_curve();
        set_G();
    }

    mpz_class get_order() { return order; }

    mpz_class get_p() { return p; }

    point get_G() {
        return this->G;
    }

    mpz_class find_biggest_prime_divisor()//делитель порядка группы //
    {
        if (kofactor == 1) { return p; }
        int div = 2;
        while (order > 1) {
            while (order % div == 0) {
                order /= div;
            }
            if (div == 2) div++;
            else div += 2;
        }
        return div - 2;
    }
};

Curve curve;
#endif //AUTHENTICATION_PROTOCOL_CURVE_HPP
