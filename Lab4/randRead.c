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
  int random;
  buffer = malloc(sizeof(char) * BUFFER_LENGTH);//gotta allocate space for our buffer array
  fp = fopen(argv[1],"r");//open the file and prepare to read the contents
  fseek(fp,0L,SEEK_END);//"0L" tells the compiler that we don't want 0 int, but rather 0 long int. "SEEK_END" simply moves file pointer position to the end of file
  long int fileSize = ftell(fp);//get the size of the file since we are pointing to the end of the file
  long int readData = 0;//using long ints since they're 64 bits, rather than 32 bits
  srand(time(NULL));//intialize the pseudo-random number generator, so we're not getting the same exact sequence everytime we use this program
  startTime = clock();//record the start time
  while(readData < fileSize){
    random = rand() % (fileSize - BUFFER_LENGTH);//get random byte that's within bounds of our array
    fseek(fp,random,SEEK_SET);//move the file position by "random" bytes from the beginning of the file
    fread(buffer, BUFFER_LENGTH,1,fp);//read in 1MB from the random location
    readData += BUFFER_LENGTH;//keep reading 1MB at a time, until we have read the entire file
  }
  endTime = clock();//record the end time once we finish reading the file 
  totalTime = ((double) (endTime-startTime))/CLOCKS_PER_SEC;//get the time used to read the file by finding the difference of the start time and end time then dividing by CLOCK_PER_SEC  
  fprintf(stdout, "Clock: %f\n", totalTime);
  fclose(fp);
  free(buffer);
  return 0;
}
