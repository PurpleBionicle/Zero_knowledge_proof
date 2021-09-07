//
// Created by ndp20 on 21.08.2021.
//

#ifndef AUTHENTICATION_PROTOCOL_POINT_HPP
#define AUTHENTICATION_PROTOCOL_POINT_HPP


#include "curve.hpp"

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

double a = 2;// коэффициент кривой
int p;


int inverse(int mod, int num) {
    if (num>=mod) {
        throw std::invalid_argument("value is bigger than module");
    }
    int x = 1, y = 0;
    int x1 = 0, y1 = 1;
    int q;
    int module =  mod;
    int num_to_inverse =  num;
    int i = 0;
    while ( mod != 1 && num != 1) {
        if ( mod > num)q =  mod / num;
        else q = num /  mod;
        if (i % 2 == 0) {
            x = x - q * x1;
            y = y - q * y1;
            mod = x * module + y * num_to_inverse;
        } else {
            x1 = x1 - q * x;
            y1 = y1 - q * y;
            num = x1 * module + y1 * num_to_inverse;
        }
        ++i;
    }
    if ( mod == 1) {
        if (y < 0)y += module;
        return y;
    } else {
        if (y1 < 0)y1 += module;
        return y1;
    }
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
            alfa = (3 * pow(B.x, 2) + a) * inverse(p,2 * B.y);
        } else {
            alfa = (B.y - this->y) * inverse(p,B.x - this->x);
        }
        A.x = (alfa * alfa - this->x - B.x) % p;
        A.y = (alfa * (this->x - A.x) - this->y) % p;
        if (A.x < 0) A.x += p;
        if (A.y < 0) A.y += p;
        return A;
    }

    point operator+=(point &B) {
        int alfa;
        if (*this == B) {
            alfa = (3 * pow(B.x, 2) + a) * inverse(p,2 * B.y);
        } else {
            alfa = (B.y - this->y) * inverse(p,B.x - this->x);
        }
        int xx = this->x;
        this->x = (alfa * alfa - this->x - B.x) % p;////Добавить по модулю p
        this->y = (alfa * (xx - this->x) - this->y) % p;////Добавить по модулю p
        if (this->x < 0) this->x += p;
        if (this->y < 0) this->y += p;
        return *this;
    }

    point operator*(int k) const {
        int k2 = two_notation(k);// в 2 сс

        point Y;
        std::vector<point> templ;
        templ.push_back(*this);

        int i = 1;
        int k_2 = k2;
        while (k_2 != 0 && k_2 != 1) //в 2 сс
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
        bool init = false; //первая точка не плюсуется с (0,0) а просто приравнивается
        for (int j = 0; j < templ.size(); ++j) {
            if (k2 % 10 != 0) {
                if (!init) {
                    result = templ[j];
                    init = true;
                } else {
                    result += templ[j];
                }
            }
            k2 /= 10;
        }
        return result;
    }
};

#endif //AUTHENTICATION_PROTOCOL_POINT_HPP
