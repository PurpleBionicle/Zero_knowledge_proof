
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

class client {
public:
    //шаг 5
    std::vector<point> client_gives_initial_points(Curve &curve) {
        int m = get_m();
        std::vector<int> x(m);
        x = generate_xi(m);

        std::vector<point> Y(m);
        for (int i = 0; i < m; ++i) {
            ////и вычисляет значения Yi =[−xi ]G, i=1,, m.
            Y[i] = curve.get_G() * ((-x[i] % curve.find_biggest_prime_divisor()) + x[i]);
            ///оператор умножения точки на число
        }
        return Y;
    }

    //шаг 4
    point clients_point(Curve &curve) {
        // вычисляет R=[k]G и отправляет проверяющему B
        // точку эллиптической кривой R.
        point R;
        int k;
        k = get_k();
        R = curve.get_G() * k;
        return R;
    }

    //шаг 5
    int clients_summation(int &bit_string) {
        int s;
        Curve curve;
        int q = curve.find_biggest_prime_divisor();
        s = (get_k() + sum(bit_string)) % q;
        if (s < 0) { s += q; }
        return 0; //////// ПОТОМ ЗАМЕНИТЬ
    }

    int get_m() {
        int m=1;
        ///Добавить РАНДОМ m
        ///причем если была инициация вернуть старое значение
        return m;
    }

private:
    //шаг 3
    int get_k() {
        //Доказывающий A генерирует случайное целое число k,
        //где 1≤k≤ q−2,

        int k;
        ///Добавить РАНДОМ К
        ///причем если была инициация вернуть старое значение
        return k;
    }

    //шаг 1
    std::vector<int> generate_xi(int &m) {
        //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
        ///ДОБАВИТЬ РАНДОМ X
        ///причем если была инициация вернуть старое значение
        std::vector<int> a;
        return a;
    }

    int sum(int &bit_string) {
        //xi с ai из bit string
        int m = get_m();
        std::vector<int> x(m);
        x = generate_xi(m);
        int binary_string = two_notation(bit_string);// в 2сс
        return 0;
    }
};


#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
