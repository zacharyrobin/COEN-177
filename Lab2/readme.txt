Ethan Paek
COEN 177 Lab #2
October 9th, 2019

Task 1: Banner Change

The first task was to search for the banner that appears upon start-up of the OS in the kernel file. To accomplish this, I used a system call named grep to locate the main.c file. From there, I was able to locate the copyright message on line 275. Thus, I added my own personal statement on line 278 at the end of the announce section, which will print: "This is Ethan Paek's super duper amazing Lab #2!". To test this, I used "make world" while in /usr/src/ to compile the OS. I then used "reboot" to restart the system and was able to clearly see my custom statement upon the new boot-up. 

Task 2: Scheduler Change

The second task involved the modification of Minix's process scheduling algorithm. To begin this, I had to figure out what kind of process scheduler that Minix utilized. In section 2.1.4. of "Operating Systems: Design and Implementation" by Andrew S. Tanenbaum and Albert S. Woodhull, I found that Minix is initialized by the reincarnation server and init processes. Furthermore, it helped me figure out that queues 0-6 are system queues so I made sure not to touch these while modifiying the code. Additionally, Section 2.5 tells us that Minix uses a multi-priority round robin scheduler.

The file that chooses the proccesses was found in proc.c of the kernel directory. More specifically, I was able to find the scheduler under the section labeled as "pick_proc" within the for loop on line 1312. Since we do not want to modify queues 0-6, I implemented the rand() function only for processes 7 through NR_SCHED_QUEUES. This was done through the following statement: q = (rand()%(NR_SCHED_QUEUES-7))+7. rand() generates a random number between 0 and 32767. We then mod the result with NR_SCHED_QUEUES-7 to ensure that the biggest number that we have is limited to NR_SCHED_QUEUES-7. We then add 7 to the result so that we are choosing only queues 7 to NR_SCHED_QUEUES at random, rather than 0 to NR_SCHED_QUEUES-7, which would be the essential processes.

To test this, I ran the same steps as Task 1. After using "make world" in the src directory, I used "reboot" to ensure that the OS still functioned properly, which it did, but at a much slower rate because it is a less efficient algorithm. Instead of going through each queue one-by-one, it now chooses the less prioritized queues at random. 
