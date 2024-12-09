[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Tfg6waJb)
# Systems Project2 - MyShell

### Ishaana Misra & Sasha Murokh
### <Insert Creative Team Name>

## Features Implemented
- basic shell functionality (prompt)
- exit to exit
- ctrl-D end of file
- cd . cd .. and cd into a directory
- parse input, parse args, run args
- redirection
## Features Attempted To Implement But Were Unsuccessful
-
## Bugs
-
## Function Headers

// prints the shell prompt
void prompt();

// parses the line of input into the command and arguments
void parse_args( char * line, char ** arg_ary );

// determines whether or not output redirection is needed
int needs_redirect(char ** args);

// main function to read input and create child processes
int take_input();

// implements output redirection by writing to given file
void redirect_output(char * command, char ** args);
