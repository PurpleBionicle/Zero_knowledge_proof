
#ifndef AUTHENTICATION_PROTOCOL_POINT_HPP
#define AUTHENTICATION_PROTOCOL_POINT_HPP


#include <utility>

#include "header.hpp"

/*! \brief переводит число в двоичную систему счисления
 *
 * @param num исходное число
 * @return число в 2сс
 */
mpz_class two_notation(mpz_class num);


//! \brief класс Point выполняет действия над точками кривой
class Point {
public:
    Point() { x = 0, y = 0; };

    Point(mpz_class xx, mpz_class yy) { x = std::move(xx), y = std::move(yy); };
    mpz_class x, y;


    //! \brief сравнивает точки
    bool operator==(const Point &B) const {
        return B.x == this->x && B.y == this->y;
    }

    //! \brief приравнивает точку
    Point operator=(const Point &B);

    //! \brief суммирование
    Point operator+(const Point &B) const;

    //! \brief суммирование
    Point operator+=(Point &B);

    //! \brief умножение точки на число
    Point operator*(const mpz_class &k) const;
};

#endif //AUTHENTICATION_PROTOCOL_POINT_HPP
