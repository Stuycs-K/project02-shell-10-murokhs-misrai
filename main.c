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
#include <signal.h>
#include <sys/wait.h>

void prompt() {
    char buffer[256];
    getcwd(buffer, 255);
    printf("%s $ ", buffer);
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    prompt();
    char user_input[256];
    fgets(user_input, 255, stdin);
    if (user_input==NULL){ //exits if end of file
      exit(0);
    }
    char* temp;
    char * input;
    strcpy(input,user_input);
    while (temp = strsep( &input, ";" )){
      printf("%s\n", temp);
      int status1;
      pid_t commands;
      commands = wait(&status1);
    }
    return 0;
}
