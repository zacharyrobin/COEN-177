#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 1024 //read in 1MB at a time

int main(int argc, char* argv[]){
  if(argc != 2){
    puts("You got the wrong amount of arguments bud. Smh and adios");
    return 0;
  }
  clock_t startTime, endTime;//clock() only returns the number of clock ticks elapsed since the program was launched
  double totalTime;
  FILE *fp;
  char* buffer;
  buffer = malloc(sizeof(char) * BUFFER_LENGTH);//gotta allocate space for our buffer array
  fp = fopen(argv[1],"r");//open the file and prepare to read the contents
  startTime = clock();//record the start time
  while(fread(buffer,BUFFER_LENGTH,1,fp) > 0);//read in the file sequentially through the buffer, 1 MB at a time
  endTime = clock();//record the end time once we finish reading the file
  totalTime = ((double) (endTime-startTime))/CLOCKS_PER_SEC;//get the time used to read the file by finding the difference of the start time and end time then dividing by CLOCK_PER_SEC
  fprintf(stdout, "Clock: %f\n", totalTime);
  fclose(fp);
  free(buffer);
  return 0;
}
