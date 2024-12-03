#include "shell_functions.h"

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
