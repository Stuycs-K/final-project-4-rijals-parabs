# This document is required.

* `strings` command helps you see strings in binary file
* `readelf -s <program>` shows you all of the symbols in a prgoram
* `dmesg | tail ` prints out latest debug messages
* `gcc -fno-stack-protector` will make it easier for attacks to attack
* gcc vuln.c -fno-stack-protector -z execstack -no-pie -g
* `sudo sysctl -w kernel.randomize_va_space=0` turns off random


GDB
- info frame: to find out what stack memory is looking like
- x/200x <address> shows the memory at that specific address



# How Data is Stored in C
![Data in C](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)
