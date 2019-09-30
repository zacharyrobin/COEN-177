#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  int children = 14;//keep track of children created
  printf("I am the allfather and my pid is %d\n", getpid());
  while (children > 0) {//must have exactly 14 children
    if (fork() == 0) {//creates the second child in the level that does nothing (has no child itself)
      printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
      break;
    } 
    else{
      waitpid(-1, NULL, 0);
    }
    if(fork() != 0) {//creates the first child in the level
      printf("My pid is %d and my parent's pid is %d\n",getpid(),getppid());
      waitpid(-1, NULL, 0);
      break;
    }
    children = children - 2;// each time, we increment the counter by 2
  } 
  return 0;
}
