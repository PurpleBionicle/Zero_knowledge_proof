

#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP
#include "header.hpp"
std::vector<point> client_gives_initial_points(Curve &curve, int &m) {
    //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2

    std::vector<int> x(m);
//////////ДОБАВИТЬ РАНДОМ X

    std::vector<point> Y(m);
    for (int i = 0; i < m; ++i) {
        ////и вычисляет значения Yi =[−xi ]G, i=1,, m.
        Y[i] = curve.get_G() * ((-x[i] % curve.find_biggest_prime_divisor()) + x[i]);
        ///оператор умножения точки на число
    }
    return Y;
}
point clients_point()
{
    point R;
    return R;
}
#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
