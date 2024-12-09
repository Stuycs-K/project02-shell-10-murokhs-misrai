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

int needs_redirect(char ** args) {
    int i = 0;

    while (args[i]) {
        if (args[i][0] == '<' || args[i][0] == '>') {
            return 1;
        }
        i += 1;
    }
    return 0;
}

//returns 0 if passed, -1 if ended
int take_input(){
  char user_input[256];
  char * input;
  prompt();
  input = fgets(user_input, 255, stdin);
  if (input==NULL){ //exits if end of file
    printf("\n");
    exit(0);
  }
  if (strcmp(user_input,"\n")==0){ //if just enter is pressed
    return 0;
  }
  char* temp;
  if (user_input[strlen(user_input)-1] == '\n');{
    user_input[strlen(user_input)-1] = '\0'; //fix newline
  }
  while (temp = strsep( &input, ";" )){
    char * args[256];
    parse_args(temp,args);
    if (strcmp(args[0],"exit")==0){
      exit(0);
      return -1;
    }
    if (strcmp(args[0],"cd")==0){
      chdir(args[1]);
    } else if (needs_redirect(args)) {
      pid_t child;
      child = fork();
      if (child==0){
        redirect_output(args[0], args);
      }
     } else{
      pid_t child;
      child = fork();
      if (child==0){
        execvp(args[0],args);
      }
  }
  int status1;
  pid_t commands;
  commands = wait(&status1);
  return 0;
  }
}

/*
    } else if (needs_redirect(args)) {
      pid_t child;
      child = fork();
      if (child==0){
        redirect_output(args[0], args);
     }
*/
void redirect_output(char * command, char ** args) {
    int i = 1;
    char * file_name;
    while (args[i]) {
        if (args[i][0] == '>') {
            printf("%s", args[i+1]);
            file_name = args[i+1];
            break;
        }
    }
    if (!file_name) {
        // throw error
    }

    args[i] = NULL;

    int save_stdout = dup(1);

    int file = open(file_name, O_WRONLY|O_TRUNC|O_CREAT, 0611);
    dup2(file, 1);

    execvp(args[0], args);

    dup2(save_stdout, 1);
    close(save_stdout);
    close(file);
}
