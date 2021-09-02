
#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP
#include "header.hpp"
#include "point.hpp"
void server()
{
    Curve curve;
    client A;
    std::vector<point>Y;
    Y= A.client_gives_initial_points(curve);

    point R= A.clients_point(curve);

    //. Проверяющий B генерирует случайную битовую строку
    // ( a1 , ..., am)∈{0, 1}m и передает ее абоненту A.
    //через Бинарные литералы
    int m= A.get_m();
    int bit_string; //длины m

    int s = A.clients_summation(bit_string);

}
#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
