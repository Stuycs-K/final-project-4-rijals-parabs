# Presentation
- Explain how memory is laid out in C
- Explain Buffer Overflow Attack
- ...
- Demo

## Introduction
For our presentation we will be discussing buffer overflow attacks. Since there are many different types of buffer overflow attacks, we will be focusing on a very specific type of attack that involves the stack.

## How Data is Stored in C
Before we discuss how the attacks work, we will need to look at how the call stack works.

The stack is datastructure that follows the FILO rule (first-in last-out). As you might have already deduced, the call stack follows a very similar rule. The call stack is a specific type of stack datastructure that applies to the function calls of a program. When

![Data in C](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

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

![overide_return_pointer](https://www.securitysift.com/wp-content/uploads/2013/12/strcpy_bof_diagram.png)


## How Can We Exploit This?

As you can see from the diagram above, it is possible to overwrite the return address. In this example it was just overwritten with a bunch of As, but if we overwrite it with something less nonsensical we will be able to access things that we normally shouldn't be able to.a

By changing the return address we can run different functions by replacing the original return address with the address of those functions. This can be used for accessing other functions in a file or for accessing functions from programs in other parts a computer storage. 

## Demo

For this demo we have a file prepared 