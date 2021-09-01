
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

std::vector<int> generate_xi(int &m) {
    //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
    ///ДОБАВИТЬ РАНДОМ X
    ///причем если была инициация вернуть старое значение
}

int get_k() {
    //Доказывающий A генерирует случайное целое число k,
    //где 1≤k≤ q−2,

    int k;
    ///Добавить РАНДОМ К
    ///причем если была инициация вернуть старое значение
    return k;
}

int get_m() {
    int m;
    ///Добавить РАНДОМ m
    ///причем если была инициация вернуть старое значение
    return m;
}

int sum(int &bit_string) {
    int m = get_m();
    std::vector<int> x(m);
    x = generate_xi(m);
    int binary_string = two_notation(bit_string);// в 2сс

}

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

point clients_point(Curve &curve) {
    // вычисляет R=[k]G и отправляет проверяющему B
    // точку эллиптической кривой R.
    point R;
    int k;
    k = get_k();
    R = curve.get_G() * k;
    return R;
}


int clients_summation(int &bit_string) {
    int s;
    Curve curve; // там конструктор надо посмотреть,чтобы генерировал стандартную кривую
    int q = curve.find_biggest_prime_divisor();
    s = (get_k() + sum(bit_string)) % q;
    if (s < 0) { s += q; }
}

#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
