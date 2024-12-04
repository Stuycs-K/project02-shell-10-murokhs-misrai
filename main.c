#include "shell_functions.h"

static void sighandler(int signo) {

}

int main(int argc, char *argv[]) {
    prompt();
    char user_input[256];
    if (user_input==NULL){ //exits if end of file
      exit(0);
    }
    char* temp;
    char * input  = fgets(user_input, 255, stdin);
    while (temp = strsep( &input, ";" )){
      char * args[256];
      parse_args(temp,args);
      if (strcmp(args[0],"exit")==0){
        exit(0);
      }
      pid_t child;
      child = fork();
      if (child==0){
        execvp(args[0],args);
      }
    }
    int status1;
    pid_t commands;
    commands = wait(&status1);
    main(argc,argv);
    return 0;
}
