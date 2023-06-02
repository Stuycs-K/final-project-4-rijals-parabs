# Presentation

## Introduction
For our presentation we will be discussing buffer overflow attacks. Since there are many different types of buffer overflow attacks, we will be focusing on a very specific type of attack that involves the stack and function addresses.

## How Data is Stored in C
Before we discuss how  attack works, we will need to breifly go over how the call stack works.

A stack is datastructure that follows the FILO paradigm (first-in last-out). As you might have already deduced, the call stack follows a very similar rule. The call stack is a specific type of stack datastructure that stores the function calls of a program. Whenver a new function is called the following occurs:
- New stack frame is created and the EBP and ESPs
- Return address to previous call stack is added at the end

<img class="img-fluid" src="https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg" alt="img-verification" height=280 width=342>


![Stack Frame](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d3/Call_stack_layout.svg/342px-Call_stack_layout.svg.png)

As
- grows from high memory address to low memory address

## Exploiting Stacks in a Buffer Overflow
Lets say you have this C program:	
```c
#include <string.h>
#include <stdio.h>
int main(int argc, char** argv){
	char buf[20];
	strcpy(buf, argv[1]);
	printf("%s\n", buf);
}
```

In short, what this program does is take a command line argument and then copy it onto a buffer of size 20.

When you compile it and run it using this command:
```
./program Hello
```
You will get the following output:
```
Hello
```

Lets say you input more characters than what the buffer can stores:
```
./program AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
```
You will get an output that looks something like this:
```
....
Segmentation fault
```

Segmentation fault basically means that somewhere in your program's execution, your program did something it wasnt allowed to do. In this case what happened was that when you initially overrode the buffer, you overrode the return pointer.

<img src="https://www.securitysift.com/wp-content/uploads/2013/12/strcpy_bof_diagram.png" height=320 width=400>


## How Can We Exploit This?

As you can see from the diagram above, it is possible to overwrite the return address. In this example it was just overwritten with a bunch of As, but if we overwrite it with something less nonsensical we will be able to access things that we normally shouldn't be able to.




By changing the return address we can run different functions by replacing the original return address with the address of those functions. This can be used for accessing other functions in a file or for accessing functions from programs in other parts a computer storage. 

## Demo

For this demo we have a file prepared with a few functions in it. When the file is run it asks for a string and then prints out the address that the function tries to access. 

First lets use ```./tool list-functions <prgm>``` to find all the functions in the program. There's a lot of stuff we don't have to worry about, but the function called win looks rather intruging. We'll take note of it's address (which is the value in the second column) for later. 

Next lets use ```./tool find-offset <prgm>``` to find the offset for the program. We will need this value too for our next step.

Now that we have both of these values we can run ```./tool override-return <prgm> <offset> <new-return-address>``` to complete our buffer overflow attack.