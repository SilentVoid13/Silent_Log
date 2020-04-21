//
// Created by silentvoid on 4/21/20.
// Copyright (c) 2020 SilentVoid. All rights reserved.
//

#include "log.h"

int main() {
    puts("");

    // Defines verbosity or not (verbose is an extern global variable)
    verbose = 1;

    log_info("This is an info message\n");
    log_success("This is a success message\n");
    log_error("This is an error message\n");
    log_warn("This is a warning message\n");
    log_verbose("This is a verbose message\n");
    log_debug("This is a debugging message\n");

    int a = 1, b = 2, c = a + b;
    // Using a format string
    log_info("%d + %d = %d !\n", a, b ,c);

    double progress;
    for(int i = 0; i <= 10; i++) {
        progress = ((double)i / 10) * 100;
        log_progress("Progress : %3.2lf", progress);
        sleep(1);
    }

    puts("\n");

    return 0;
}

