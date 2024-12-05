#ifndef shell_functions_h
#define shell_functions_h

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

int take_input();
void prompt();
void parse_args( char * line, char ** arg_ary );
void dir();

#endif
