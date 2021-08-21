#include "header.hpp"

int two_notation(int num) {
    int result = 0, k = 1;

    while (num) {
        result += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return result;
}

point multi(int xi, point G, double a) {
    point Yi;

    int alfa = (3 * pow(G.x, 2) + a) / (2 * G.y);
    Yi.y = -G.y;
    Yi.x = pow(alfa, 2) - 2 * G.x;
    return Yi;
}

int Proving(int64_t p, int64_t q, double a) {
    //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
    //и вычисляет значения Yi =[−xi ]G, i=1,, m.
    int m = 1;
    std::vector<int> x(m);
    point G;
    //xi в 2сс : необходимо для минимизации числа итераций
    for (int i = 0; i < m; ++i) {
        std::vector<int> x_2_notation(m);
        x_2_notation[i] = two_notation(x[i]);
    }
    //умножение [xi]*G;
    std::vector<point> Y(m);
    for (int i = 0; i < m; ++i) {
        Y[i] = multi(x[i], G, a);
    }
    return 0;
}

int main() {
    //Proving    //Verifier
    //elliptical curve y^2=x^3+ax+b
    double a, b;
    int64_t p = 1, q = 1;
    Proving(p, q, a);

    return 0;
}