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

void prompt() {
    char buffer[256];
    getcwd(buffer, 255);
    printf("%s $ ", buffer);
    fflush(stdout);
}

void input() {
  char user_input[256];
  fgets(user_input, 255, stdin);
  char* temp;
  char * input;
  strcpy(input,user_input);
  while (temp = strsep( &input, ";" )){
    printf("%s\n", temp);
  }
}

int main(int argc, char *argv[]) {
    prompt();
    input();
    return 0;
}
