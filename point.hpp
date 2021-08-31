//
// Created by ndp20 on 21.08.2021.
//

#ifndef AUTHENTICATION_PROTOCOL_POINT_HPP
#define AUTHENTICATION_PROTOCOL_POINT_HPP
#include "header.hpp"

int two_notation(int num) {
    //перевод из 10сс в 2сс
    // необходимо для минимизации числа итераций суммирования
    int result = 0, k = 1;

    while (num) {
        result += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return result;
}

class point {
public:
    point() { x = 0, y = 0; };

    point(int xx, int yy) { x = xx, y = yy; };
    int x, y;

    bool operator==(point &B) const {
        if (B.x == this->x && B.y == this->y) return true;
        return false;
    }

    point operator=(point B) {
        this->y = B.y;
        this->x = B.x;
        return *this;
    }

    point operator+(point &B) const {
        point A;
        int alfa;
        if (*this == B) {
            alfa = (3 * pow(B.x, 2) + a) / (2 * B.y);
        } else {
            alfa = (B.y - this->y) / (B.x - this->x);
        }
        A.x = pow(alfa, 2) - this->x - B.x; ////Добавить по модулю p
        A.y = alfa * (this->x - A.x) - this->y;////Добавить по модулю p
        return A;
    }

    point operator+=(point &B) {
        int alfa;
        if (*this == B) {
            alfa = (3 * pow(B.x, 2) + a) / (2 * B.y);
        } else {
            alfa = (B.y - this->y) / (B.x - this->x);
        }
        this->x = pow(alfa, 2) - this->x - B.x;////Добавить по модулю p
        this->y = alfa * (this->x - this->x) - this->y;////Добавить по модулю p
        return *this;
    }

    point operator*(int k) const {
        int k2 = two_notation(k);// в 2 сс

        point Y;
        std::vector<point> templ;
        templ.push_back(*this);

        int i = 1;
        int k_2 = k2;
        while (k_2) //в 2 сс
        {
            Y = templ[i - 1] + templ[i - 1];
            templ.push_back(Y);
            // вектор сложенных частей (G,2G,4G, и тд степени двойки)-
            // max степень - размер xi
            k_2 /= 10;
            ++i;
        }
        //теперь из этих степеней двойки собираем наше число
        point result;
        for (int j = 0; j < templ.size(); ++j) {
            if (k2 % 10 != 0) { result += templ[j]; }
            k2 /= 10;
        }
        return result;
    }
};

#endif //AUTHENTICATION_PROTOCOL_POINT_HPP
