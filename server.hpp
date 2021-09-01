
#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP
#include "header.hpp"
#include "point.hpp"
void server()
{
    Curve curve;
    std::vector<point>Y;
    Y= client_gives_initial_points(curve);

    point R= clients_point(curve);

    //. Проверяющий B генерирует случайную битовую строку
    // ( a1 , ..., am)∈{0, 1}m и передает ее абоненту A.
    //через Бинарные литералы
    int m= get_m();
    int bit_string; //длины m

    ++++-++++++++++++++++int s = clients_summation(bit_string);

}
#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
