
#ifndef AUTHENTICATION_PROTOCOL_CLIENT_HPP
#define AUTHENTICATION_PROTOCOL_CLIENT_HPP

#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

//! \brief класс Client демонстрирует действия доказывающего
class Client {
public:

    Client();

    //! \brief отправляет точки эллиптической кривой - полученные умножением G на закрытые ключи
    virtual
    std::vector<Point> client_gives_initial_points();

    //! \brief отправляет открытый ключ - полученный умножением случайного числа на G
    virtual
    Point clients_point();

    /*! \brief отправляет результат на challenge от сервера
     * \param[in] binary_string challenge от сервера
    */
    virtual
    mpz_class clients_summation(mpz_class &binary_string);

private:
    int m;

    std::vector<mpz_class> xi;

    mpz_class k;

    //! \brief запрашивает у пользователя закрытые ключи
    void choose_xi();

    //! \brief генерирует число ,которое даст открытый ключ сеанса
    void generate_k();

    //! \brief суммирует закрытые ключи ,умноженные на challenge
    mpz_class sum(mpz_class &bit_string);

};

#endif //AUTHENTICATION_PROTOCOL_CLIENT_HPP
