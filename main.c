#include "shell_functions.h"

int main(int argc, char *argv[]) {
    //prompt();
    char user_input[256];

    if (user_input==NULL){ //exits if end of file
      exit(0);
    }
    char* temp;
    char * input  = fgets(user_input, 255, stdin);
    while (temp = strsep( &input, ";" )){
      if (strcmp(temp,"exit")==0){
        printf("exiting\n");
        kill(getpid(), SIGINT);
      }
      pid_t child;
      child = fork();
      if (child==0){
        char * args[256];
        parse_args(temp,args);
        execvp(args[0],args);
      }
    }
      //int status1;
      //pid_t commands;
      //commands = wait(&status1);
    return 0;
}
