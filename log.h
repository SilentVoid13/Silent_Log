#ifndef LOG_H
#define LOG_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define RED "\x1b[38;5;196m"
#define GREEN "\x1b[38;5;46m"
#define BLUE "\x1b[38;5;33m"
#define YELLOW "\x1b[38;5;226m"
#define ORANGE "\x1b[38;5;202m"

#define RESET "\x1b[0m"

#define INFO_SYMBOL BLUE "*" RESET
#define WARN_SYMBOL YELLOW "!" RESET
#define ERROR_SYMBOL RED "-" RESET
#define SUCCESS_SYMBOL GREEN "+" RESET
#define DEBUG_SYMBOL ORANGE "?" RESET

#define LOG_INFO(msg, ...) \
    fprintf(stderr, "[" INFO_SYMBOL "] " msg, ##__VA_ARGS__);

#define LOG_WARN(msg, ...) \
    fprintf(stderr, "[" WARN_SYMBOL "] " msg, ##__VA_ARGS__);

#define LOG_ERROR(msg, ...) \
    fprintf(stderr, "[" ERROR_SYMBOL "] " msg, ##__VA_ARGS__);

#define LOG_SUCCESS(msg, ...) \
    fprintf(stderr, "[" SUCCESS_SYMBOL "] " msg, ##__VA_ARGS__);

#ifdef DEBUG
#define LOG_DEBUG(msg, ...) \
    fprintf(stderr, "[" DEBUG_SYMBOL "] " msg, ##__VA_ARGS__);
#else
#define LOG_DEBUG(...) {}
#endif

#endif // LOG_H
