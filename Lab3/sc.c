#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
  int tableSize;
  if(argc == 2 && (tableSize = atoi(argv[1]))) {
    return tableSize;
  }
  fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
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
  int pageRequest, totalPages = 0, pageTableIndex = 0, numRequest = 0, numMisses = 0;
  int *pageTable = (int *) malloc(sizeof(int)*tableSize);
  int *refPageTable = (int *) malloc(sizeof(int)*tableSize);
  char *input = NULL;
  size_t inputAllocated = 0;
  ssize_t bytesRead;
  FILE *fp;
  fp = fopen("epaekscoutput.txt", "w");
  
  while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
    pageRequest = atoi(input);
    if(pageRequest == 0) {
      continue;
    }
    numRequest++;
    if(!isInMemory(pageRequest, pageTable, tableSize)) {
      fprintf(fp,"Page %d caused a page fault.\n", pageRequest);
      numMisses++;
      if(totalPages < tableSize-1) {//if the table isn't full, we can insert directly into the array
	totalPages++;
	pageTable[pageTableIndex] = pageRequest;
	refPageTable[pageTableIndex] = 0;
	pageTableIndex = (pageTableIndex+1)%tableSize;//use circular array, in case we need to wrap around to the beginning of the array
      } 
      else{//if the table is full and the page doesn't already exist in the array, we need to replace the oldest one
	while(refPageTable[pageTableIndex] == 1){
	  refPageTable[pageTableIndex] = 0;
	  pageTableIndex = (pageTableIndex+1)%tableSize;
	}
	pageTable[pageTableIndex] = pageRequest;
	refPageTable[pageTableIndex] = 0;
	pageTableIndex = (pageTableIndex+1)%tableSize;
      }
    }
    else{//if the item already exists in our main memory, we need to set its reference bit
      for(int k = 0; k < tableSize; k++){
	if(pageRequest == pageTable[k]){
	  refPageTable[k] = 1;
	  break;
	}
      }
    }
  }
  fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
  printf("We had a total of %d requests and %d misses! Not too shabby ol chap...\n", pageRequest, numMisses);
    
  fclose(fp);
  free(input);
  free(pageTable);
  free(refPageTable);
  return 0;
}
