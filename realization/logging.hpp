

#ifndef AUTHENTICATION_PROTOCOL_LOGGING_HPP
#define AUTHENTICATION_PROTOCOL_LOGGING_HPP

#include "header.hpp"

//! \brief возвращает дату завершения программы
std::string add_date() {
    std::string j;
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    j = std::to_string(ltm->tm_mday) + "." + std::to_string(1 + ltm->tm_mon)
        + "." + std::to_string(1900 + ltm->tm_year) + " "
        + std::to_string(ltm->tm_hour) + ":";
    if (std::to_string(ltm->tm_min).size() == 1) { j += "0"; }
    j += std::to_string(ltm->tm_min);
    return j;
}

/*! записывает в лог файл время и результат программы, выбранный режим
 *
 * @param flag результат программы
 * @param error сообщение об ошибки
 */
void log(const bool flag, const std::string &error, const int &mode) {
    freopen("../Logging.jsonl", "a", stderr);
    json j;
    j["date"] = add_date();
    if (mode == 1) { j["mode"] = "Prover"; }
    else if (mode == 2) { j["mode"] = "Attacker"; }
    else { j["mode"] = "not important"; }
    if (flag && error.empty()) {
        if (!file_log.fail()) {
            j["answer"] = "ACCEPTED";
            std::clog << j << "\n";
        }
    } else if (error.empty()) {
        if (!file_log.fail()) {
            j["answer"] = "DENIED";
            std::clog << j << "\n";
        }
    } else {
        j["answer"] = "DENIED";
        j["error"] = "curve is singular";
        std::clog << j << "\n";
    }
    file_log.close();
}

#endif //AUTHENTICATION_PROTOCOL_LOGGING_HPP
