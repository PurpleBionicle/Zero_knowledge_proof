

#ifndef AUTHENTICATION_PROTOCOL_CURVE_HPP
#define AUTHENTICATION_PROTOCOL_CURVE_HPP
#include "header.hpp"
#include "point.hpp"
//Secp256k1
///FULL
//p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F;
//а = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
//б = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000007
//Наконец, порядок n группы G :
//
//n = FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFE BAAEDCE6 AF48A03B BFD25E8C D0364141
//
//x = 0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
//y = 0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8

class Curve{
    //elliptical curve y^2=x^3+ax+b
private:
    int p ; // Zp
    point G;//базовая точка
    int order ; //порядок группы  |Ep(a, b)|
    double a,b; // коэффициенты кривой
public:
    point get_G()
    {
        return this->G;
    }
    int find_biggest_prime_divisor()//делитель порядка группы /// УДАЛИТЬ ТК КОФАКТОР РАВЕН 1
    {
        int div = 2;
        while (order > 1)
        {
            while (order % div == 0)
            {
                order /= div;
            }
            if (div == 2) div++;
            else div += 2;
        }
        return div-2;
    }
};
#endif //AUTHENTICATION_PROTOCOL_CURVE_HPP
