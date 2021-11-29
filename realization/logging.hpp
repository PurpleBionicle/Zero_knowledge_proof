

#ifndef AUTHENTICATION_PROTOCOL_LOGGING_HPP
#define AUTHENTICATION_PROTOCOL_LOGGING_HPP

#include "header.hpp"

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

void log(const bool flag, const std::string &error) {
    freopen("Logging.txt", "a", stderr);
    std::clog << add_date();
    if (flag && error.empty()) {
        if (!file_log.fail()) {
            std::clog << " answer: ACCEPTED\n";
        }
    } else if (error.empty()) {
        if (!file_log.fail()) {
            std::clog << " answer: DENIED\n";
        }
    } else {
        std::clog << " error:" << error << " answer: DENIED\n";
    }
    file_log.close();
}

#endif //AUTHENTICATION_PROTOCOL_LOGGING_HPP
