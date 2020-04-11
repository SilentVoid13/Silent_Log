#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define RED "\x1b[0;31m"
#define BOLD_RED "\x1b[1;31m"
#define GREEN "\x1b[0;32m"
#define BOLD_GREEN "\x1b[1;32m"
#define BLUE "\x1b[0;34m"
#define BOLD_BLUE "\x1b[1;34m"
#define YELLOW "\x1b[0;33m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_ORANGE "\x1b[48;2;255;165;0m"
#define RESET "\x1b[0m"

extern int verbose;

void log_info(char *msg, ...);
void log_verbose(char *msg, ...);
void log_success(char *msg, ...);
void log_debug(char *msg, ...);
void log_error(char *msg, ...);
void log_progress(char *msg, ...);

void log_format(const char* message, va_list args);
void log_format_error(const char *message, va_list args);

#ifdef _WIN32

#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <errno.h>

#ifndef FOREGROUND_MASK
#define FOREGROUND_MASK (FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#endif

#ifndef BACKGROUND_MASK
#define BACKGROUND_MASK (BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY)
#endif

int __write_w32(FILE* fp, const char* buf);
int _fprintf_w32(FILE* fp, const char* format, ...);

#define printf(...) _fprintf_w32(stdout, __VA_ARGS__)

#endif // _WIN32

#endif // LOG_H
