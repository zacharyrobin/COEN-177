#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  printf("The OG process is: %d\n", getpid());//Test the program to find the original process ID
  for(int i = 0; i < 6; i++){//we must only do exactly 6 child processes
    if(fork() != 0){//fork off of child process, test if it's the parent process; if it doesn't return to the newly created child process
      waitpid(-1, NULL, 0);//wait for any child process to finish
      break;//necessary so that we don't keep forking off of the child processes
    }
    else{
      printf("Child is %d, and its Father (or Mother?) is %d\n", getpid(), getppid());
    }
  }
  return 0;
}
