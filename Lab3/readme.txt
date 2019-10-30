Ethan Paek
COEN 177 Lab #3
October 30th, 2019

First In, First Out (FIFO)

In the FIFO algorithm, I used a queue to represent the page table. Whenever a new page number is requested, it first checks if it's present in the main memory/cache. If it is already present, then we do not need to do anything. Otherwise, we check if the queue is completely filled up or not. If it is not, then we simply add the page number to the next nearest spot. In the case of it being already filled, then we shift every element to the left by one spot, which gets rid of the element at index 0, since it is the oldest, and insert at the last spot of the queue.

Least Recently Used (LRU)

In LRU, similar to FIFO, we first check if our page number is already in the main memory or not. If it is already present, we need to move it to the front of the queue (index 0). To do this, we first traverse the array and find the index as to where our page number is located. We then shift everything to the left by one from that spot and update the location of our page request to index 0, which is where all of the most least recently used pages are located. If the page is not memory, we essentially perform FIFO, but by shifting every element by one spot to the right (rather than the left) and inserting at index 0.

Second Chance (SC)

For second chance, I implemented this algorithm by using a circular array. I used one array to store all of the page numbers and another to store the reference bits. If we try to insert a page number that's already present in the main memory, then all we do is change its reference bit to 1 to signify that page number's second chance. If it is not present, then we traverse the array based on our index, finding the first element that has its reference bit set to 0 and insert the new page at that location. While we are traversing, if we come across any page with a reference bit of 1, we set it back to 0 and keep going, signifying its use of the second chance.


To test the correctness of these three algorithms, I ran each algorithm against the sample input of 100 and compared these outputs with the expected outputs. I also found how each of these algorithms behave with different cache sizes which can be found in the file page_comparison_graph.xlsx