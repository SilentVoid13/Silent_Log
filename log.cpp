#include "log.hpp"

int verbose;

// TODO : Find a better than using va_start with reference type

void log_info(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    printf("[" BLUE "*" RESET "] ");
    log_format(msg.c_str(), args);
    printf("\n");
    va_end(args);
}

void log_verbose(const std::string &msg, ...) {
    if(verbose == 1) {
        va_list args;
        va_start(args, msg);
        printf("[" GREY "#" RESET "] ");
        log_format(msg.c_str(), args);
        printf("\n");
        va_end(args);
    }
}

void log_success(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    printf("[" GREEN "+" RESET "] ");
    log_format(msg.c_str(), args);
    printf("\n");
    va_end(args);
}

void log_debug(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    printf("[" ORANGE "?" RESET "] ");
    log_format(msg.c_str(), args);
    printf("\n");
    va_end(args);
}

void log_warn(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    printf("[" YELLOW "!" RESET "] ");
    log_format(msg.c_str(), args);
    printf("\n");
    va_end(args);
}

void log_error(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    fprintf(stderr, "[" RED "-" RESET "] ");
    log_format_error(msg.c_str(), args);
    fprintf(stderr, "\n");
    va_end(args);
}

void log_progress(const std::string &msg, ...) {
    va_list args;
    va_start(args, msg);
    printf("\r[" BLUE "*" RESET "] ");
    log_format(msg.c_str(), args);
    va_end(args);
    fflush(stdout);
}

void log_format(const char* message, va_list args) {
    vprintf(message, args);
}

void log_format_error(const char *message, va_list args) {
    vfprintf(stderr, message, args);
}

