#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  while(1){//while loop so that the user chooses when to exit, not the computer
    puts("Type 'exit' to quit the program or literally anything else to launch the amazing Hello World program!");
    char input[10];
    scanf("%s", input);
    if(!strcmp(input, "exit")){//if the user types "exit," we quit the program
      break;
    }
    else{
      if(fork() != 0){//fork off child process; tests whether it's the parent process
	waitpid(-1, NULL, 0);//wait for child (Hello World) to finish; -1 in first parameter refers to waiting for the child process
      }
      else{//execute Hello World program
	execve("./helloworld", NULL, NULL);
      }
    }
  }
  return 0;
}
