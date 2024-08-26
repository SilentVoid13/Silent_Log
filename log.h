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

#define LOG_INFO(...)                             \
    do {                                          \
        fprintf(stderr, "[" BLUE "*" RESET "] "); \
        fprintf(stderr, __VA_ARGS__);             \
    } while (0);

#define LOG_WARN(...)                          \
    do {                                            \
        fprintf(stderr, "[" YELLOW "!" RESET "] "); \
        fprintf(stderr, __VA_ARGS__);               \
    } while (0);

#define LOG_ERROR(...)                      \
    do {                                         \
        fprintf(stderr, "[" RED "-" RESET "] "); \
        fprintf(stderr, __VA_ARGS__);            \
    } while (0);


#ifdef DEBUG
#define LOG_DEBUG(...)                         \
    do {                                            \
        fprintf(stderr, "[" ORANGE "?" RESET "] "); \
        fprintf(stderr, __VA_ARGS__);               \
    } while (0);
#else
#define LOG_DEBUG(...) {}
#endif

#endif // LOG_H
