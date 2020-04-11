# Silent_Log

Silent_Log is a really simple library you can add to any of your C / C++ project to display some nice and pretty log messages. My code is surely not perfect, do not hesitate to make pull requests or to contact me for any problems / code enhancement suggestion at [silentvoid13@protonmail.com](mailto:silentvoid13@protonmail.com).

Silent_Log includes the following log functions : 

- `log_info`
- `log_success`
- `log_error`
- `log_verbose`
- `log_warn`
- `log_debug`
- `log_progress`

Silent_Log supports string formatting. It's based on ANSI colors and supports Windows terminals.

You can suggest me or add yourself a new type of logging message.

## Usage

To use it in your code, nothing is more simple, just add the file `log.c` in your sources and include the header file `log.h`.

Here is a C example : 

```c
#include <stdio.h>
#include <unistd.h>

// Defines prototypes
#include "log.h"

int main(int argc, char **argv) {
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
        return 1;
}
```

## Example

```bash
cd examples
gcc -I.. -o example example.c ../log.c
./example
```
![Demo gif](examples/demo.gif)

## License

Silent_Log is licensed under the GNU AGPLv3 license. Refer to [LICENSE](https://github.com/SilentVoid13/Silent_Log/blob/master/LICENSE.txt) for more informations.

## Resources

To add Windows ANSI color support, Silent_Log relies on this great project : https://github.com/mattn/ansicolor-w32.c
