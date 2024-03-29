#include <stdio.h>

int main(){
  printf("The OG process is: %d\n", getpid());//Test the program to find the original process ID
  int i;
  for(i = 0; i < 6; i++){//we must only do exactly 6 child processes
    if(fork() != 0){//fork off of child process, test if it's the parent process; if it doesn't return to the newly created child process
      waitpid(-1, NULL, 0);//wait for any child process to finish
      break;//necessary so that we don't keep forking off of the child processes and create more children by accident; fork() would create an identical process with the same exact instructions
    }
    else{
      printf("Child is %d, and its Father (or Mother?) is %d\n", getpid(), getppid());
    }
  }
  return 0;
}
