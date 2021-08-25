**Description**

*Home tasks are:*
1. Write a function that copies a string to a new one dynamically allocated.
The function should return the new string address or NULL in case of error.
Avoid using the standard functions from string.h.
2. Write a stack library based on a linked list. Minimum set of operations: push(), pop().
3. Write a queue library based on an array. Minimum set of operations: enqueue(), dequeue().
4. Write the "map" function that receives an array of items, its size, and a function
to apply individually to each item of the array. "map" could modify existing array 
or return a new one.
5. [OPTIONAL] Explain how the code from the title slide works (or unfold
the code in text, make it simpler).

**Requirements**

*Linux (Ubuntu)*<br>
gcc 9.3.0

*Windows*<br>
gcc 8.1.0

**Build project**
- To build the specific program run one of the commands in 'Terminal' from the root project directory:<br>
``gcc task1.c -o task1``<br>
``gcc task2.c stack.c -o task2``<br>
``gcc task3.c queue.c -o task3``<br>
``gcc task4.c -lm -o task4``<br>

**Run the program in Terminal**
- To run the specific program run one of the commands in 'Terminal' from the root project directory:<br>
``./task1``<br>
``./task2``<br>
``./task3``<br>
``./task4``<br>
