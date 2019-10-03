Ethan Paek
September 25th, 2019
Lab Session: Wednesdays 5:15 - 8 PM

This program is designed in order to fully comprehend the creation of processes with Unix-like operating systems while focusing on the fork() call.

Task 1: Shell will terminate if the user enters "exit" at the command line and will launch a Hello World program in reponse to any other string. 

How it Works: Upon initialization, there is a constant while loop that doesn't exit unless prompted by the user. It takes a user input with the scanf() function and will only exit if the user types "exit". Any other input will result in executing the helloworld program which simply outputs "Hello World". This is completed by using the fork() function. If we happen to fork and still be in the parent process, then we use waitpid() and wait for any child process to finish. Otherwise, if we are on the child process, then we simply execute the helloworld program.

Testing: To test this program, I used "exit" to see if the program would exit and tried entering words, letters, numbers, special characters, and some combination of the four. Any other input resulted in running the helloworld program.

Task 2: This program will create exactly 6 child processes (not including the initial program itself). It will not allow any single process to create more than two child processes.

How it Works: We first print the initial process ID to ensure that our children are forking off of the parent. We then enter a for loop that increment exactly six times since we only require six children processes. Similar to task 1, if we happen to fork and still be in the parent process, then we must wait for any child process to finish. Furthermore, we have a break statement so that we don't keep forking off of the initial child processes and create more children than intially intended. fork() would create an identical process with the same exact instructions. Otherwise, if we happen to be in the child process, then we simply output the child's ID and the parent's ID to keep track of where the processes are.

Testing: To test this, I made sure to output the root process ID first and then ensure that exactly six children are being outputted. Furthermore, I made sure the child ID are corresponding to the parent IDs. They are constructed linearly or in other words, each process makes a total of only one child process.

Task 3: This program will result in a total of 14 child processes to run. It is similar to task 2 except for the fact that it will not allow any single process that creates children to create less than two child processes or more than three. In other words, the program can only launch a maximum of 3 child processes directly and any other children will have to be created by the children of this parent process.

How it Works: To accomplish this, I used a while loop and set an int at 14 and decremented by two each time since I created two children through each run of the while loop. To begin with, if we were in the child process, then we immediately outputted the child's information in addition to the parent's. Otherwise, we waited for the child process to finish. After that, we created the second child by running the opposite. If we happened to be in the parent process, then we waited for any child process to finish. Otherwise, we printed the child's ID and the parent's ID. 

Testing: This was very similar to task 2. We had to ensure that we were outputting the root process ID and made exactly fourteen children. Each parent could only have two children.
