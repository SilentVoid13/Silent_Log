#ifndef LOG_H
#define LOG_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif // _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef _WIN32

#define RED 	"\x1b[38;5;196m"
#define GREEN 	"\x1b[38;5;46m"
#define BLUE	"\x1b[38;5;33m"
#define YELLOW 	"\x1b[38;5;226m"
#define ORANGE 	"\x1b[38;5;202m"
#define GREY	"\x1b[38;5;240m"

#define RESET "\x1b[0m"

#else

#define RED
#define GREEN
#define BLUE
#define YELLOW
#define ORANGE
#define GREY

#define RESET

#endif

extern int verbose;

void log_info(char *msg, ...);
void log_verbose(char *msg, ...);
void log_success(char *msg, ...);
void log_debug(char *msg, ...);
void log_warn(char *msg, ...);
void log_error(char *msg, ...);
void log_progress(char *msg, ...);

void log_format(const char* message, va_list args);
void log_format_error(const char *message, va_list args);

#endif // LOG_H
