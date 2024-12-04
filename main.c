#include "shell_functions.h"

int main(int argc, char *argv[]) {
    prompt();
    char user_input[256];

    if (user_input==NULL){ //exits if end of file
      exit(0);
    }
    char* temp;
    char * input  = fgets(user_input, 255, stdin);
    while (temp = strsep( &input, ";" )){
      printf("%s\n", temp);
      //int status1;
      //pid_t commands;
      //commands = wait(&status1);
    }
    return 0;
}
