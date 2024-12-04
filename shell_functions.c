#include "shell_functions.h"

void prompt() {
    char buffer[256];
    getcwd(buffer, 255);
    printf("%s $ ", buffer);
    fflush(stdout);
}

void parse_args( char * line, char ** arg_ary ) {
    int index = 0;
    char *token;
    while(token = strsep(&line, " ")) {
        arg_ary[index] = token;
        index += 1;
    }
    arg_ary[index] = NULL;
}
