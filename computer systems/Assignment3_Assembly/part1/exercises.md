
In a brief sentence or two,  modify this file with your answers.

1. In each of the programs what was the bug?  *TODO (Add your answers here)*
2. What file and lines did the bugs occur? *TODO (Add your answers here)*
3. What would your educated guess be for a fix for each bug? *TODO (Add your answers here)*

In *prog*, the bug occurred on line 57. It produced a SIGSEGV error code with a segmentation fault, returning the gdb message that *prog2.c* does not exist. This is most likely occurring because the program is trying to access memory space that does not exist, such as an additional element in an array. Right before the error occurs, the program prints a linked list of the alphabet, leading me to believe that line 57 is attempting to access a pointer in the linked list that does not exist. 

In *prog1*, gdb detects a bug on line 15. Once again, gdb prints a SIGSEGV segmentation fault, most likely caused by trying to access memory which the program does not have access to. Based on the line in question,
`0x000000400535 in initialize_front() at seg.c:15`
I would assume that the program is trying to initialize a memory space which has not yet been allocated. 
