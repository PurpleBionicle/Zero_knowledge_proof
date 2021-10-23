
#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP

#include "header.hpp"
#include "point.hpp"
#include "client.hpp"
#include "curve.hpp"

point sum(mpz_class bit_string, std::vector<point> &Y) {
    //Yi с ai из bit string
    point result;
    int i = 0;
    while (bit_string) {
        point current = Y[Y.size() - 1 - i] * (bit_string % 2);
        result += current;
        ++i;
        bit_string /= 2;
    }
    return result;
}

bool check_equality(point &R, mpz_class &s,
                    std::vector<point> &Y, mpz_class binary) {
    point a = curve.get_G() * s;
    point b = sum(binary, Y);
    return R == a + b;
}

void server() {

    client A;

    std::vector<point> Y;
    Y = A.client_gives_initial_points();

    point R = A.clients_point();

    //. Проверяющий B генерирует случайную битовую строку
    // ( a1 , ..., am)∈{0, 1}m и передает ее абоненту A.
    //Предупреждение об ожидаемом результате генерации
    // - но строка публичная
    srand(time(nullptr));
    mpz_class bit_string = rand() % static_cast<int>(pow(2, Y.size())); //длины m
    mpz_class binary = two_notation(bit_string);
    mpz_class s = A.clients_summation(binary);

    //Теперь если выполнено равенство
    if (check_equality(R, s, Y, binary))
        std::cout << "ПРИНЯТО";
    else std::cerr << "ОТКАЗАНО";
    //то  проверяющий  B  принимает  доказательство;
    // если  равенство не выполнено, то отвергает.
}

#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
