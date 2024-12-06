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

//returns 0 if passed, -1 if ended
int take_input(){
  char user_input[256];
  char * input;
  prompt();
  while(input = fgets(user_input, 255, stdin)){
    char* temp;
    if (user_input==NULL){ //exits if end of file
      exit(0);
      return -1;
    }
    if (strcmp(user_input,"\n")==0){
      break;
    }
    user_input[strlen(user_input)-1] = '\0'; //fix newline
    while (temp = strsep( &input, ";" )){
      char * args[256];
      parse_args(temp,args);
      if (strcmp(args[0],"exit")==0){
        exit(0);
        return -1;
      }
      if (strcmp(args[0],"cd")==0){
        chdir(args[1]);
      }
      else{
        pid_t child;
        child = fork();
        if (child==0){
          execvp(args[0],args);
        }
      }
    }
    int status1;
    pid_t commands;
    commands = wait(&status1);
    return 0;
  }
}
