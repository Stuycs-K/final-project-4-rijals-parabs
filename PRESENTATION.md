## Terms to Know
In order to understand buffer overflows, we will have to understand the follwoing concepts first:
- Buffer: 
- Stack: 
- Pointer:


## How Data is Stored in C
![Data in C](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

For buffer overflows, we will mainly be concerned about the stack. Some things to note about the stack:
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

In short, what this program does it takes a command line argument and then copies it onto a buffer of size 20.

```
When you compile it an run it using this command:
```
./program Hello
```
You will get the following output:
```
Hello
```

Lets say you input more characters than what the buffer can stores:
```
./program AAAAAAdkfjsdkfjsdkfjsdlfjsdlfjsdlkfjsdklfjsdlkfjsdl
```
You will get an output that looks something like this:
```
....
Segmentation fault
```

Segmentation fault basically means that somewhere in your program's execution, your program did something it wasnt allowed to do. In this case what happened was that when you initially overrode the buffer, you overrode the return pointer.

![overide_return_pointer](https://www.securitysift.com/wp-content/uploads/2013/12/strcpy_bof_diagram.png)


### How Can We Exploit This?

