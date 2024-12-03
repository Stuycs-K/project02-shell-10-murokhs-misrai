#include "shell_functions.h"

void prompt() {
    char buffer[256];
    getcwd(buffer, 255);
    printf("%s $ ", buffer);
    fflush(stdout);
}
