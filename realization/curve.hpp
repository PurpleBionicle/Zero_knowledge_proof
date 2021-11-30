

#ifndef AUTHENTICATION_PROTOCOL_CURVE_HPP
#define AUTHENTICATION_PROTOCOL_CURVE_HPP

#include "header.hpp"
#include "point.hpp"
#include "logging.hpp"

//шаг 4
/*! \brief проверяет выбранную кривую на сингулярность
 *
 * \param[in] aClass коэффициент кривой
 * \param[in] b коэффициент кривой
 * в случае сингулярности выводит соответсвующий результат в лог файл и заканчивает программу
 */
void singularity(const mpz_class &aClass, const mpz_class &b) {

    if (4 * aClass * aClass * aClass + 27 * b * b == 0) {
        log(false, "curve is singularity");
        exit(1);
    }
}

/*! \brief класс Curve задает параметры эллиптической кривой
 *
 * p- модуль поля
 * G-базовая точка
 * order- порядок группы
 * a,b- коэффициенты ,задающие уравнение кривой
 * kofactor - кофактор . Отношение порядков группы и уиклической подгруппы
 */
class Curve {
    //elliptical curve y^2=x^3+ax+b
    //Secp256k1
private:
    mpz_class p; // Zp
    Point G;//базовая точка
    mpz_class order;
    mpz_class a, b; // коэффициенты кривой
    int kofactor = 1;

    //! \brief определяет параметр выбранной кривой
    void set_order();

    //! \brief определяет параметр выбранной кривой
    void set_coeff(int &k);

    //! \brief определяет параметр выбранной кривой
    void set_p();

    //! \brief определяет параметр выбранной кривой
    void set_G();

public:
    Curve();

    //шаг2-3
    //! \brief выбор кривой пользователем
    void choose_curve(int &k) {
        set_coeff(k);
        singularity(a, b);
    }

    //! \brief функция-геттер
    mpz_class get_order() { return order; }

    //! \brief функция-геттер
    Point get_G() {
        return this->G;
    }

    //! \brief находит по кофактору точку циклической подгруппы и ее порядок
    mpz_class find_biggest_prime_divisor();//делитель порядка группы //
};

Curve::Curve() {
    set_order();
    set_p();
    set_G();
    int i = 2;
    set_coeff(i);
}

void Curve::set_order() {
    mpz_class order1("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
    order = order1;
}

void Curve::set_coeff(int &k) {
    if (k == 1) {
        a = 0;
        b = 0;
    } else {
        mpz_class a1("0", 16);
        a = a1;
        mpz_class b1("7", 16);
        b = b1;
    }
}

void Curve::set_p() {
    mpz_class p1("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 16);
    p = p1;
}

void Curve::set_G() {
    mpz_class x1("79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 16);
    G.x = x1;
    mpz_class y1("483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 16);
    G.y = y1;
}

mpz_class Curve::find_biggest_prime_divisor()//делитель порядка группы //
{
    if (kofactor == 1) { return order; }
    /* int div = 2;
     while (order > 1) {
         while (order % div == 0) {
             order /= div;
         }
         if (div == 2) div++;
         else div += 2;
     }
     return div - 2;*/
}

Curve curve;

#endif //AUTHENTICATION_PROTOCOL_CURVE_HPP
