# Queue and Stack

# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

The queue is a 'first-in, first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed. This project will implement a specific implementation of a queue using an array in the [myqueue.h](./myqueue.h) file. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).

## Circular Queue (Ring Buffer) implementation using an array.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

## Part 3 - Why is a ring buffer/circular queue useful?

Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and edit this section of the readme answering specifically: Why is a ring buffer useful and/or when should it be used?

## Answer

The most important feature of a ring buffer is its ability to make a finite amount of memory more "infinite". Infinite is a relative term here, of course. However, the structure of a ring buffer is such that it allows a certain amount of space to effectively hold more data. Where a linear queue must allocate additional memory space for additional data, the ring buffer is capable of reusing memory once it reaches capacity, making it more spacially efficient.

Because the ring buffer only keeps track of the head and tail at any given time, it is very efficient. Rather than parsing through an entire list of objects to make any changes, the enqueue and dequeue functionalities of the ring buffer are actually fairly straightforward and not terribly expensive.

Ring buffers should be utilized when memory is to be dynamically allocated for data storage. If there is a lot of data that is constantly changing, the ring buffer provides the ideal functionality in C.


# Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working queue implementation. A sample unit tests is given:

```c
void unitTest1(){
	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);
	printf("Removing: %d\n",queue_dequeue(test1));

	free_queue(test1);
}
```

You *may* also consider writing some unit tests to test your implementation (In fact, I would strongly encourage you to do so). Note that you can include your unit tests in your submission, and we will have our own test suite. Some example tests we might come up with include:

* Fill a queue, empty the queue, and fill the queue again.
* Create an empty queue and attempt to add something to it.
* Make sure your queue does not overwrite any data.
* etc.

## Provided Tests

You are provided a file called queue_test.c which you can compile separately and test your implementation of your queue functions from your header file. Doing so does not guareentee a perfect assignment, but it will give you some confidence your implementation is working.

* Compile: `gcc queue_test.c -o queue_test`
* Run: `./queue_test`

# Rubric

* Your implementation will be graded by our set of unit tests, and we will check your code 'style' as well.

<table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>
    <tr>
      <td>45% (Queue Implementation)</td>
      <td align="left"><ul><li>All functions should be implemented.</li><li>You did not rename any functions (but you may add any 'helper' functions if you deem necessary--e.g. queue_print)</li><li>There should be no memory leaks</li><li>There should be no bugs in your functions </li></ul></td>
    </tr>
    <tr>
      <td>5% (Writeup)</td>
      <td align="left"><ul><li>Correct writeup on the importance of queues/ring buffers as related to OS</li><li>I expect this to be in the range of 2-3 paragraphs (Can include complexity, example usage, pros/cons, etc).</li></ul></td>
    </tr>
  </tbody>
</table>


# Resources to help

- [http://www.learn-c.org/](http://www.learn-c.org/)
	- This is a nice interactive tutorial for learning C
- [https://en.wikipedia.org/wiki/Queue_(abstract_data_type)](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
	- Queue Data Type High level description

# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * queue_peek - Returns the first value in the queue
  * queue_back - Returns the last value in the queue
  * queue_equals - Checks if two queues are equal


* Information on pros/cons of our header only design
	* https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient
* Some examples (Revisit this again in a few weeks)
	* https://github.com/nothings/single_file_libs  

# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based queue here!
  - Use them as a *rough* guide for the basic concepts. Do make sure to follow the specifications for our assignment above.
