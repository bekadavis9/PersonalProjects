## Static Analysis 
 
Our Cycle Count Tool is what we call a 'static analysis'. That is, it uncovers information about our programs before it is running (during compile-time). Given that our tool uncovers information before the program, what is (at least) one pro of this, and one con you can think of?

Pro:
1. The program has a faster run-time because it doesn't have to fetch as much information.

Con:
1. Some information could potentially change during run-time, causing errors in the program. 

## Dynamic Analysis

The opposite of a static analysis is a dynamic analysis. Dynamic analysis tools record and return information about programs that are in the process or have finished executing. An example of a dynamic analysis tool is [valgrind](http://valgrind.org/). What do you think a pro and con of dynamic analysis would be?

Pro:
1. There is less room for error, since everything is done after the program is compiled and is running. Compilation will find any errors in the program  which can be fixed and the program should run smoothly. 

Con:
1. The program could run a bit slower with the added execution steps of getting information.
