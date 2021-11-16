
#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP

#include "header.hpp"
#include "point.hpp"
#include "client.hpp"
#include "curve.hpp"

Point sum(mpz_class bit_string, std::vector<Point> &Y) {
    //Yi с ai из bit string
    Point result(0, 0);
    int i = 0;
    while (bit_string) {
        Point current = Y[Y.size() - 1 - i] * (bit_string % 10);
        result += current;
        std::cout<<"bit="<<bit_string%10<<"\n";
        std::cout<<"current="<<current.x<<"\n";
        std::cout<<"current="<<current.y<<"\n";
        std::cout<<"result="<<result.x<<"\n";
        std::cout<<"result="<<result.y<<"\n";
        ++i;
        bit_string /= 10;
    }
    return result;
}

bool check_equality(Point &R, mpz_class &s,
                    std::vector<Point> &Y, mpz_class &binary) {
    Point sG = curve.get_G() * s;
    Point d = sum(binary, Y) + sG;
    std::cout<<d.x<<"\n";
    std::cout<<d.y<<"\n";
    std::cout<<R.x<<"\n";
    std::cout<<R.y<<"\n";
    return R == d;
}


void server() {


    Client A;

    std::vector<Point> Y;
    Y = A.client_gives_initial_points();

    Point R = A.clients_point();

    //. Проверяющий B генерирует случайную битовую строку
    // ( a1 , ..., am)∈{0, 1}m и передает ее абоненту A.
    //Предупреждение об ожидаемом результате генерации
    // - но строка публичная

    srand(time(nullptr));
    mpz_class bit_string = rand() % static_cast<int>(pow(2, Y.size())); //длины m
    mpz_class binary = two_notation(bit_string);// в двоичную 
    std::cout << binary << "\n";
    mpz_class s = A.clients_summation(binary);


    //Теперь если выполнено равенство
    if (check_equality(R, s, Y, binary)) {
        std::cout << "ПРИНЯТО";
    } else {
        std::cerr << "ОТКАЗАНО";
    }
}

#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
