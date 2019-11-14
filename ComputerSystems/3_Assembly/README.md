# Introduction

<img align="right" width="300px" src="./media/GDB-screenshot.gif">

By now you have been writing code in the C language for over a week, and it can be helpful to have some tools that assist you to verify the correctness of those programs. You are going to start by learning how to use a debugger that will be useful for both C and assembly programming (as well as any other future language you use in your career).

# Part 1 - GDB Introduction 

GDB is a debugger for the programs that we are compiling with the GCC compiler. It helps us track down errors in our program. As an example, you may use gdb to step through programs and execute one line at a time to understand what is going on. Learning how to debug errors through a debugger is an essential skill for all computer scientists!

## GDB Training

1. Watch the following video from Greg Law: *Give me 15 minutes and I'll change your view of GDB* [https://www.youtube.com/watch?v=PorfLSr3DDI](https://www.youtube.com/watch?v=PorfLSr3DDI)
2. Next browse this tutorial to get a little more familiar with GDB: [https://www.cs.cmu.edu/~gilpin/tutorial/](https://www.cs.cmu.edu/~gilpin/tutorial/)
3. Then follow the walkthrough below based on the video to get some practice.
	- This will be potentially helpful for the rest of the assignments in this course!

## GDB Walkthrough with a sample program

Provided below is a program called [hello2.c](./hello2.c) (It is the same one from the Greg Law video).

```c
#include <stdio.h>

int main(void){
        int i =0;
	printf("Hello, world\n");
        printf("i is %d\n",i);
	i++;
	printf("i is now %d\n",i);

        return 0;
};
```

Compile the program with debug symbols(The *-g* flag does this).
- `gcc hello2.c -g -o hello2`
- `gdb ./hello2`
- Then run the program by typing `r` when inside gdb.
	- The program is now executing as normal--however it is being monitored by the gdb debugger.

## GDB TUI (Text User Interface)

Here are the instructions for the TUI part of the Greg Law video (roughly) written out so you can follow along. Practice using them with the program above.

- Type: `start`
- Type: `list`
- You can type `next` (or simply `n`) to execute the next line of code.
- Then press [Ctrl+x a] (Press Ctrl and x at the same time, then press 'a' key after--this may take practice)
  - (Pressing [Ctrl+x a] again will bring you back to just the gdb terminal)
  - Note: If you are having trouble with Ctrl+x, you can type `gdb ./hello -tui` to launch the program.
- Typing in 'next' again moves another line (or simply hit 'enter' which repeats the previous command).
- Ctrl+L will clear the screen after the text prints to clean it up.
- Now try hitting [Ctrl+x 2]
  - You will now see multiple windows with the assembly and the source code.
  - Pressing [Ctrl+x o] will cycle between the windows.
  - Hitting [Ctrl+x 2] a couple of times will cycle through the windows to show what is in the registers.
    - Typing `tui reg` will give some options to see specific registers.
      - For example, `tui reg float` shows the floating registers.
      - For example, `tui reg general` displays the general purpose registers.
 - Hit [Ctrl+x 1] to go back to the first view and see your source code.
   - Typing in some commands like 'layout src' will bring you back to your source view.
     - Typing in 'layout asm' will show you the assembly.
- More: [https://sourceware.org/gdb/onlinedocs/gdb/TUI-Commands.html#TUI-Commands](https://sourceware.org/gdb/onlinedocs/gdb/TUI-Commands.html#TUI-Commands)
- More: [https://sourceware.org/gdb/onlinedocs/gdb/TUI-Keys.html#TUI-Keys](https://sourceware.org/gdb/onlinedocs/gdb/TUI-Keys.html#TUI-Keys)
- More resources on GDB TUI: [https://sourceware.org/gdb/onlinedocs/gdb/TUI.html](https://sourceware.org/gdb/onlinedocs/gdb/TUI.html)
  
## (Optional) GDB Python	

From the Greg Law Video, he demonstrates using an the Python programming langauge within the GDB Tool. Python is a general purpose scripting langauge--perhaps you have even used it! What is neat about Python is that the languages interpreter can be embedded into other tools (and even other programming languages!) as has been shown with GDB.

Here are some of the Python commands written out for your convenience. 
	
- Try the following within GDB:
  - Type: `python print("hello gdb")`
  - Type: `python import os`
  - Type: `python print("my pid is %d" % os.getpid()) # pid = process id`
  - If you have inserted any breakpoints:
    - (Create one with `b main`)
    - Type: `python print(gdb.breakpoints())`
    - Type: `python print(gdb.breakpoints()[0].location)`
    - With Python, you can even create breakpoints!
      - `python gdb.Breakpoint('7')`
    
- Finally typing in `quit` will exit gdb when you are done.





# Going Further

## Core dumps

In the Greg Law video, he begins to investigate a Core dump file. What exactly is a coredump?

Read here: [https://wiki.archlinux.org/index.php/Core_dump](https://wiki.archlinux.org/index.php/Core_dump)

# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

<img align="right" width="300px" src="./media/ddd.png">

- There is a Visual Debugger built on top of gdb that you may use called DDD ([Data Display Debugger](https://www.gnu.org/software/ddd/))
	- DDD is not installed on the servers unfortunately, so you may only use it on your local environment.
	- Since DDD is built on top of GDB (and some other debuggers), everything you learned in gdb you can also use.
	- There are also handy visualizations of data structures as well.
	- A video tutorial on how to use it is displayed here: [https://www.youtube.com/watch?v=VF7IBEAA8Ig](https://www.youtube.com/watch?v=VF7IBEAA8Ig)





# Part 2 Assembly - Writing Functions in Assembly

# Introduction

For this part of the assignent you are going to be practicing  [Assembly programming](https://en.wikipedia.org/wiki/Assembly_language)! Note that, in the past when teaching assembly, I have noted that this can be a more difficult assignment for the following reasons:

## Assignment Strategy

1. You cannot simply dive into the code without a plan.
2. You really should do the readings, or at least study an assembly cheat sheet before and while you are attempting the assignment.
3. You should use the [compiler generated assembly](https://godbolt.org/) as a helper--but only use really really small examples to test your understanding (It will be obvious if you write your code in C, and submit the assembly--you may not do that). 
4. Luckily--for this assignment we are taking a small jump into the assembly. In future courses, you may write some assembly from scratch!
5. Finally, I have recorded a few videos on assembly programming that may be of use: 
[https://www.youtube.com/playlist?list=PLvv0ScY6vfd9BSBznpARlKGziF1xrlU54](https://www.youtube.com/playlist?list=PLvv0ScY6vfd9BSBznpARlKGziF1xrlU54) -- these won't solve all problems, but hopefully give you a kickstart!



## Assembly Refresher

We have previously looked at some examples of assembly code. And we additionally have an understanding of how the stack stores data in memory by pushing in data. "Removing" data is then done by manipulating the stack pointer which is stored in the %rsp register (remember, %rsp always points to the top of the stack). There are some concerns however that you may have in your mind:

- How do I write 'functions' in assembly to make assembly code writing *easier* and more *maintainable*.?
- If we only have 16 registers, how can I write functions with a lot of arguments?
- How do I jump into a function and return back to where I left off?

You might have yet more questions even--and that is wonderful! Remember, assembly programming is sort of similar to solving a puzzle and getting everything to fit just right. Let me however remind you to the jobs of a procedure/function/method to orient you with what we must achieve:

1. Pass control
	- Start executing from start of procedure.
	- Return back to where we called from.
2. Pass data
	- Procedure arguments and return value are passed.
3. Memory management
	- Memory allocated in the procedure, and then deallocated on return.
4. Try to do this in the most minimal way.

## Background on functions

<img align="right" width="400px" src="http://www.cs.virginia.edu/~evans/cs216/guides/stack-convention.png" alt="Stack from http://www.cs.virginia.edu/~evans/cs216/guides/x86.html">

Writing a function in assembly almost follows a 'design recipe', and it is very useful to draw a picture of the stack (an example is shown to the right) as you write your function. Think of a function as broken into three different parts.

1. The setup - Sets up our stack
2. The body - Does the work
3. The finish/return - Pops things off the stack so we can resume execution to where we left off.

### The setup

This is where we are starting the execution of our function. Typically, it looks something like this

```asm
pushq %rbp
movq %rsp, %rbp
pushq %rbx
```

### The body

This is where the work is done.

### The finish/return

This is where we have to pop our stack, because we are done with our temporary (i.e. local) variables. Our temporaries or local variables are things like the arguments of a function that were passed in. Typically this looks something like this:

```asm
movq -8(%rbp),%rbx
movq %rbp, %rsp
popq %rbp
ret
```

## Assembly Example 1

I want to provide a few assembly examples, so you can see how the work is done. Try these examples first before jumping straight into assembly programming. This first example is of using a subroutine, or a sort of 'function call' with no arguments. This is a nice way to keep our code relatively clean.

```asm
# Assemble with
# 1.) gcc - c funcion.s
# 2.) ld function.o -o function
# 3.) ./function
.global _start

# Here we have a label, and we directly place some ASCII text
# into our program.
.welcome:
    .ascii "Welcome to this example\12" # A 24 character long
                                        # string. Note the \12
                                        # at the end is a 'line feed'
.text

# _printWelcome is a subroutine (i.e. a block of code we can execute)
# This is one way to 'modularize' our code.
_printWelcome:
    movq $1, %rax
    movq $1, %rdi
    leaq .welcome,%rsi # Load effective address, is a
    movq $24, %rdx
    syscall
    ret

# A subroutine to exit the program
_exit:
    movq $60, %rax
    xor %rdi, %rdi
    syscall

# The entry point into our program
_start:

    call _printWelcome
    call _exit
```

## Assembly Example 2

Here is an example of a simple function that is provided by a nice set of videos: [https://www.youtube.com/watch?v=S-ZDUYMoy3Y&list=PLHMcG0zmCZcj7hKyHgQGGEZ41UWKaISKU](https://www.youtube.com/watch?v=S-ZDUYMoy3Y&list=PLHMcG0zmCZcj7hKyHgQGGEZ41UWKaISKU) See if you can follow along! I recommend watching all of the videos to truly understand the work being done--they might be helpful for Task 1!

## Task 1

Your task is to write two assembly functions--an `long add(long, long)` and `long subtract(long,long)` function in a file called *function.s*. A user will select which of the two functions to execute before terminating. A sample of the output from your program should look something like the following.

```
Select an operation
1 - add
2 - subtract
1
6
5
11
```

Here is the same output with my comments (To make it clear)

```
Select an operation # Use a syscall to write this out
1 - add		    # Use a syscall to write this out
2 - subtract        # Use a syscall to write this out
1 		    # The user selected '1'
6                   # The first input
5                   # The second input
11                  # 6+5 = 11, so print out '11' 
                    # Note: if this had been subtraction 
		    # (i.e. user selected '2' at the start), it would be 6-5 = 1                   
```

Some things I foresee in this assignment that may be tricky are:

- How to get user input.
- Think about if we read in a '1' is that stored as a *long with a value of 1* or some other representation of the ascii 1.
	- What if we sum to relatively large numbers, like 5000 and 6000? How would we output them, and would it be useful to have a function to do so?







# Part 3 - Cycle Count Tool

## Introduction

You may be wondering how good are compilers at generating assembly from our C code (Similar to the way you may have a good and bad translator when communicating in different languages)? How can we be sure that our compiler is generating efficient assembly? There are afterall, many different ways to write a program that generates the same output.

## Our Tool

Part of being a good systems programmer, is the ability to build tools that measure. In this case, you are going to write a small parser in C that counts the number of instructions and counts how many instructions are needed to run that program from top to bottom.

As an example, if an assembly program had the following code:

```asm
MOVQ a, %rax
MOVQ b, %rbx
ADDQ %rbx, %rax
IMULQ %rbx
MOVQ %rax, c
```

Your [tool.c](./tool.c) will report a summary of the total Instructions(i.e. ADDQ, MOVQ, IMUQ, etc.) found. Additionally, you will estimate the total cycles needed for hardware to execute this code.

```asm
ADD 1
MOV 3
IMUL 1

Total Instructions = 5
Total Cycles = ???
```

## Specifications for tool.c

* Your tool should read in a file name through the command line arguments for what file is being analyzed 
  * You will run your program with: `./tool barbones.s`
  * (hint, investigate what argc and argv are for how to read in `barebones.s` as input to your program).
* [barebones.s](./barebones.s) is provided to be used as an example input file for your tool.
* You will modify a file called [tool.c](./tool.c) which you will implement your tool in. 
  * At the very least, your program should output counts for: ADD, SUB, MUL, DIV, MOV, LEA, PUSH, POP, RET.
    * i.e. For your analysis (and for the sake of simplicity), consider ADDQ, ADDB, ADDL, etc. each as an 'ADD' instruction.
* You may find [https://fresh2refresh.com/c-programming/c-strings/c-strcat-function/](https://fresh2refresh.com/c-programming/c-strings/c-strcat-function/) helpful for learning some string processing in C.
* Use the Agner Fog's instruction table ([http://www.agner.org/optimize/instruction_tables.pdf](http://www.agner.org/optimize/instruction_tables.pdf)) to estimate how many cycles the program will run. That is, take an instruction like MOV which typically takes 1 cycle, and sum them together and output the result.
  * You will use the **Nehalem** Intel architecture to find your values.
  * Note that this is again an estimate (MOV with different data types itself takes different number of cycles! So your answer will be an approximation. I am expecting there to be some variance, even within the class--attempt something reasonable).
 
