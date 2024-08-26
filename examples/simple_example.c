// if debug is not set, LOG_DEBUG is suppressed
#define DEBUG
#include "log.h"

int main() {
    LOG_INFO("This is an info message\n");
    LOG_ERROR("This is an error message\n");
    LOG_WARN("This is a warning message\n");

    int a = 1, b = 2, c = a + b;
    LOG_INFO("%d + %d = %d !\n", a, b, c);

    LOG_DEBUG("This is a debugging message\n");

    return 0;
}
