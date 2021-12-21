

#ifndef AUTHENTICATION_PROTOCOL_LOGGING_HPP
#define AUTHENTICATION_PROTOCOL_LOGGING_HPP

#include "header.hpp"

//! \brief возвращает дату завершения программы
std::string add_date();

/*! записывает в лог файл время и результат программы, выбранный режим
 *
 * @param flag результат программы
 * @param error сообщение об ошибки
 */
void log(const bool flag, const std::string &error, const int &mode);

#endif //AUTHENTICATION_PROTOCOL_LOGGING_HPP
