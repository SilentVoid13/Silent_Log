# Silent_Log

This is a dead simple single-header library to display some colored log messages, based on ANSI colors.

It offers the following functions: 
- `LOG_INFO`
- `LOG_ERROR`
- `LOG_WARN`
- `LOG_DEBUG`

## Usage

To use it in your code, just include the header file `log.h`.

```c
// if debug is not set, LOG_DEBUG is suppressed
#define DEBUG
#include "log.h"


int main() {
    LOG_INFO("This is an info message\n");
    LOG_ERROR("This is an error message\n");
    LOG_WARN("This is a warning message\n");

    int a = 1, b = 2, c = a + b;
    LOG_INFO("%d + %d = %d !\n", a, b ,c);

    LOG_DEBUG("This is a debugging message\n");

    return 0;
}
```

## License

Silent_Log is licensed under the GNU AGPLv3 license. Refer to [LICENSE](https://github.com/SilentVoid13/Silent_Log/blob/master/LICENSE.txt) for more informations.
