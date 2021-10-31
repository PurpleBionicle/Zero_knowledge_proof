
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

class client {
public:
    client() {
        //шаг 1
        std::cout << "write how many x do you have\n";
        std::cin >> m;
        std::cout << "\n";
        //шаг 2
        choose_xi();
        //шаг 3
        generate_k();
    }

    //шаг 4
    std::vector<point> client_gives_initial_points() {

        std::vector<point> Y(m);
        for (int i = 0; i < m; ++i) {
            ////и вычисляет значения Yi =[−xi ]G, i=1,, m.
            mpz_class mult=(-xi[i]) %p;
            if (mult<0) mult+=p;
            Y[i] = curve.get_G() * mult;
        }
        return Y;
    }

    //шаг 5
    point clients_point() {
        // вычисляет R=[k]G и отправляет проверяющему B
        // точку эллиптической кривой R.
        point R;
        R = curve.get_G() * k;
        return R;
    }

    //шаг 6
    mpz_class clients_summation(mpz_class binary_string) {
        mpz_class s;
        mpz_class q = curve.find_biggest_prime_divisor();

        s = (k + sum(binary_string)) % q;
        if (s < 0) { s += q; }
        return s;
    }


private:
    int m;
    std::vector<mpz_class> xi;
    mpz_class k; // рандом

    //шаг 2
    void choose_xi() {
        //Абонент A выбирает случайные числа xi , 1≤xi≤ q−2
        std::cout << "write x[i]\n";
        for (int i = 0; i < m; ++i) {
            mpz_class current;
            std::cin >> current;
            xi.push_back(current);
        }
    }

    //шаг 3
    void generate_k() {
        //Доказывающий A генерирует случайное целое число k,
        //где 1≤k≤ q−2,
//       mpz_random(k.get_mpz_t(), reinterpret_cast<mp_size_t>
//                                  (curve.find_biggest_prime_divisor().get_mpz_t()) - 2);
        srand(time(nullptr));
        k = rand();
    }

    //шаг 6.5
    mpz_class sum(mpz_class &bit_string) {
        //xi с ai из bit string
        mpz_class result = 0;
        int i = 0;
        while (bit_string) {
            result += (bit_string % 10) * xi[m - 1 - i];
            ++i;
            bit_string /= 10;
        }
        return result;
    }

};


#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
