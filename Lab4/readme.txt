Ethan Paek
COEN 177 Lab #4
November 15th, 2019

To setup my program, I needed files of the following sizes: 0.1 GB, 0.5 GB, 1 GB, 5 GBs, and 10 GBs. In order to make these files, I used the following command in Unix: "head -c N /dev/urandom Ngigs.txt"
For example, to create a file that's 1 GB, I ran: "head -c 1000MB /dev/urandom 1gig.txt"
I used these five text files to test the time it took to read an entire file sequentially and randomly through a buffer that is 1 MB. In other words, both programs read 1 MB at a time, until it has analyzed the entire the text file.

To run and test my programs, I would compile the respective C program and input one of the text files as a parameter.
For another example, to test my sequential read program after compiling on my one gig text file, I ran: "./a.out 1gig.txt"

Sequential Read (seqRead.c)

This program records the time it takes to read files sequentially with a buffer of 1024 bytes.

To do this, I used a file pointer that reads the file 1024 bytes (~1 MB) at a time. Using a while loop, I make sure the program only continues reading when data was not read the previous time by utilizing fread(), and stops reading when it reaches end of file.

Random Read (randRead.c)

I wrote this file to test the time it takes to read files from random locations in one of the specified text files. Similar to seqRead.c, it takes in a file path at execution. The program still reads 1024 bytes at a time, but the starting place for each read is different.

To do this, I first used several system functions to determine the size of the file that was taken in as input during execution, since the computer does not explicity tell us this. When the program reads the file, it generates a random number that is anywhere between 0 to fileSize-BUFFER_LENGTH. From that random location, 1024 consecutive bytes is read. This is repeated until the number of bytes read is the same as the file size.

Observations and Analysis (readVSsequential.png, output.txt)

As we can see from my output.txt, reading randomly takes much more time to complete as compared to sequential reading. This is because instead of reading the file in order in 1 MB increments, randomly reading forces us to calculate a new offset each time and jump around the file, reading 1 MB at whichever spot it lands at, causing it.