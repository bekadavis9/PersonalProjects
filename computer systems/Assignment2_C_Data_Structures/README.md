# Queue and Stack

# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

The queue is a 'first-in, first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed. This project will implement a specific implementation of a queue using an array in the [myqueue.h](./myqueue.h) file. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).


## Circular Queue (Ring Buffer) implementation using an array.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)


# Building Data Structures - Stack
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Lifo_stack.png/350px-Lifo_stack.png" alt="Stack picture">

A 'stack' data structure is analogous to how you might wash dishes at a restaurant. A dirty dish is placed near the sink, and you pick it up to begin washing it. As customers bring in more dirty dishes, they are stacked on top of each other. With this ordering, the newest dirty-dish is placed on the top. This makes a stack a  'last-in first-out' (LIFO) data structure. Thus stacks have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a stack using a linked list in the [mystack.h](./mystack.h) file.

## Part 1 - Stack implementation using a linked list.

Our stack has two fundamental operations that it can perform:

1. push - Add elements to the top of the stack.
2. pop  - Remove elements from the top of the stack.

You will notice, both of these operations happen at *the top of the stack*. Sometimes, we also refer to these operations as 'enqueue' or 'dequeue' so we have a consistent langauge for our data structures.

Our stack that we are implementing can expand dynamically, thus a linked list is a good foundational data struturre to use in our implementation.

Our stack can push elements onto it, until `MAX_DEPTH` is reached. MAX_DEPTH is defined as 32 for our implementation. For our implementation, we are artificially setting this limit. Remember however, we only have a finite amount of memory on our systems, so if we had very large stacks, we could get a [stack overflow](https://en.wikipedia.org/wiki/Stack_overflow).

* Compile: `gcc stack_test.c -o stack_test`
* Run: `./stack_test`


# Unit Tests

Unit tests are provided for both the stack and queue to test their functionalities. 
