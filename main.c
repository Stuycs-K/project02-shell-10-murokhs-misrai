#include "shell_functions.h"

static void sighandler(int signo) {

}

int main(int argc, char *argv[]) {
  int result = 0;
    while(result==0){
      result = take_input();
    }
    return 0;
}
