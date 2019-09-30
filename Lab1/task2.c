#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  printf("The OG process is: %d\n", getpid());//Test the program to find the original process ID
  for(int i = 0; i < 6; i++){//we must only do exactly 6 child processes
    if(fork() != 0){//fork off of child process, test if it's the parent process
      waitpid(-1, NULL, 0);//wait for child process to finish
      return 0;//return 0 will return flow of control to the method caller
    }
    else{
      printf("Child is %d, and its Father (or Mother?) is %d\n", getpid(), getppid());
    }
  }
  return 0;
}
