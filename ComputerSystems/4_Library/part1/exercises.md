(In a brief sentence or two)

1. What do you notice that is different about the functions(*Hint* search for foo)? 

While all of the other lines in the objdump output have an address followed by `l df`, the functions have addresses followed by `g F`. Also, all of the addresses are 0x0, but main and foo have address offsets of 14. 

2. Do we have some information that could be useful for LD_PRELOAD if we were writing a function to override that function? That is, what information do we need to use to name a function?

In order to name a function, the .text library must be implemented. Preloading this into the program could increase efficiency.  

3. How many add_generic functions are there? What is your best guess for what the compiler is doing behind the scenes to implement the 'templating' feature?

There are 8 add_generic functions in the objdump - 4 with the `l d` flags and 4 with the `w F` flags. I would assume the compiler is allocating space for the outputs of each add_generic function and then running them. 
