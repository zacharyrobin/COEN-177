Ethan Paek
September 25th, 2019
Lab Session: Wednesdays 5:15 - 8 PM

This program is designed in order to fully comprehend the creation of processes with Unix-like operating systems while focusing on the fork() call.

Task 1: Shell will terminate if the user enters "exit" at the command line and will launch a Hello World program in reponse to any other string. 

Task 2: This program will create exactly 6 child processes (not including the initial program itself). It will not allow any single process to create more than two child processes.

Task 3: This program will result in a total of 14 child processes to run. It is similar to task 2 except for the fact that it will not allow any single process that creates children to create less than two child processes or more than three. In other words, the program can only launch a maximum of 3 child processes directly and any other children will have to be created by the children of this parent process.
