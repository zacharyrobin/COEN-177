#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
  int tableSize;
  if(argc == 2 && (tableSize = atoi(argv[1]))) {
    return tableSize;
  }
  fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");//exit the program if we have the incorrect amount of arguments or the incorrect variable type in the command-line
  exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
  int i;
  for(i = 0; i < tableSize; i++) {
    if(pageRequest == pageTable[i]) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int tableSize = parseArguments(argc, argv);
  int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0;
  int *pageTable = (int *) malloc(sizeof(int)*tableSize);
  char *input = NULL;
  size_t inputAllocated = 0;
  ssize_t bytesRead;
  FILE *fp;
  fp = fopen("epaekfifooutput.txt", "w");

  while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {//go through the file and exit if we fail to read a line
    pageRequest = atoi(input);
    if(pageRequest == 0) {
      continue;
    }
    numRequest++;
    if(!isInMemory(pageRequest, pageTable, tableSize)) {
      fprintf(fp, "Page %d caused a page fault.\n", pageRequest);
      numMisses++;//increment our number of misses if we have a page fault, signifying that it's not in our main memory 
      if(pageTableIndex < tableSize) {//check if we can hold more pages
	pageTable[pageTableIndex++] = pageRequest;//insert into the array
      } 
      else {//if array is full, then we need to perform FIFO, which means to remove the first page from the queue and queue both and insert the current page
	for(int i = 0; i < tableSize-1; i++){
	  pageTable[i] = pageTable[i+1];//shift all the elements by one space towards the front since we want to remove the oldest page from the queue
	}
	pageTable[tableSize-1] = pageRequest;
      }
    }
  }
  fprintf(fp, "Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
  printf("We had a total of %d requests and %d misses! Not too shabby ol chap...\n", pageRequest, numMisses);

  fclose(fp);
  free(input);
  free(pageTable);
  return 0;
}
