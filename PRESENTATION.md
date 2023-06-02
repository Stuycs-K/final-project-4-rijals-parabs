# Presentation

## Introduction
For our presentation we will be discussing buffer overflow attacks. Since there are many different types of buffer overflow attacks, we will be focusing on a very specific type of attack that involves the stack and function addresses.

## How Data is Stored in C
Before we discuss how attack works, we will need to breifly go over how memory works. Here is a diagram that provides a general overview:

<img class="img-fluid" src="https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg" alt="img-verification" height=280 width=342>

*Note how the stack grows from high memory addresses to low memory addresses.*

Since we are focusing on stack based buffer overflow attacks, we will need to familiarize ourselves with the call stack. A stack in general is a datastructure that follows the FILO paradigm. A call stack is very similar. Everytime you call a function a `stack-frame` is pushed onto the stack and at the end of a function call the stack-frame is popped out. Here is a helpful diagram:

![Stack Frame](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d3/Call_stack_layout.svg/342px-Call_stack_layout.svg.png)

*Note how every stack has a return address. This address points back to the calling stack-frame*

## Overriding the Call Stack
Most buffer overflow attack are based on overriding the return address. The return address lets the call stack know what instruction to execute next. If an attacker is able to control the value of this address, they are able to control the execution of a program.

Lets say you have this C program:	
```c
#include <string.h>
#include <stdio.h>
int main(int argc, char** argv){
	char buf[20];
	gets(buf);
}
```

When you compile and run this program, one of the first things that will happen is that 20 bytes of memory will be allocated to `buf`. Then the function `gets` (never use this function btw) will prompt the user for input. If the user specifies an input that is 20 bytes or less, the program will exit normally. However, if the user is malicious and inputs more than 20 bytes, then the extra input will override other areas of the call stack. Here is a visualization:

<img src="https://www.securitysift.com/wp-content/uploads/2013/12/strcpy_bof_diagram.png" height=320 width=400>

User inputs with sizes greater than what the buffer can hold will leek onto other parts of memory which include the function paramers, other local variables and even the return address.

## How Can We Exploit This?

In the example above the return address was overwritten by a bunch of As. If we overwrite it with something less nonsensical we will be able to do things that we normally shouldn't be able to. Let's try to do this for this [vulnerable program](demo/vuln).

First lets run it:
```
./vuln
```

Segmentation fault basically means that somewhere in your program's execution, your program did something it wasnt allowed to do. In this case what happened was that when you initially overrode the buffer, you overrode the return pointer.




By changing the return address we can run different functions by replacing the original return address with the address of those functions. This can be used for accessing other functions in a file or for accessing functions from programs in other parts a computer storage. 

## Demo of our Tool

For this demo we have a file prepared with a few functions in it. When the file is run it asks for a string and then prints out the address that the function tries to access. 

First lets use ```./tool list-functions <prgm>``` to find all the functions in the program. There's a lot of stuff we don't have to worry about, but the function called win looks rather intruging. We'll take note of it's address (which is the value in the second column) for later. 

Next lets use ```./tool find-offset <prgm>``` to find the offset for the program. We will need this value too for our next step.

Now that we have both of these values we can run ```./tool override-return <prgm> <offset> <new-return-address>``` to complete our buffer overflow attack.