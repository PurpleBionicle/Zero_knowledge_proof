

#ifndef AUTHENTICATION_PROTOCOL_SERVER_HPP
#define AUTHENTICATION_PROTOCOL_SERVER_HPP
#include "header.hpp"
void server()
{
    Curve curve;
    int m = 10; ///какое m выбрать
    std::vector<point>Y(m);
    Y= client_gives_initial_points(curve,m);
   // point R= clients_point();

}
#endif //AUTHENTICATION_PROTOCOL_SERVER_HPP
