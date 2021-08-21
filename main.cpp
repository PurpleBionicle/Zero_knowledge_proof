#include "header.hpp"
#include "point.hpp"

//elliptical curve y^2=x^3+ax+b
//double b, a; // коэффициенты



void client(int64_t p, int64_t q) {
    //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
    //и вычисляет значения Yi =[−xi ]G, i=1,, m.
    int m = 1;
    std::vector<int> x(m);
    point G;

    std::vector<point> Y(m);
    for (int i = 0; i < m; ++i) {
        Y[i] = G * x[i];
    }

}

int main() {
    //clients     //server
    int64_t p = 1, q = 1;
    client(p, q);

    return 0;
}