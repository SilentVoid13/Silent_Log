#ifndef LOG_H
#define LOG_H

// For vasprintf
#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define RED 	"\x1b[38;5;196m"
#define GREEN 	"\x1b[38;5;46m"
#define BLUE	"\x1b[38;5;33m"
#define YELLOW 	"\x1b[38;5;226m"
#define ORANGE 	"\x1b[38;5;202m"
#define GREY	"\x1b[38;5;240m"

#define RESET "\x1b[0m"

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
