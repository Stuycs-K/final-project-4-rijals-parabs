# Work Log

## Sunil Parab

### 5/19/23

- Reviewed C coding
	- watched [this video](https://www.youtube.com/watch?v=ZCVwB6HJ2wk) to understand pointers
- Watched videos on buffer overflow attacks to understand what they are / how they work
	- https://www.youtube.com/watch?v=1S0aBV-Waeo
	- https://www.youtube.com/watch?v=oS2O75H57qU

### 5/22/23

- Researched how to access memory of other programs in C
	- Found [this](https://stackoverflow.com/questions/68866194/can-you-access-another-programs-stack-heap-if-you-know-the-address), nothing really useful
- Tested out doing a buffer overflow attack to better understand them

### 5/23/23

- Successfully did a buffer overflow attack
- Read [this](https://www.comp.nus.edu.sg/~liangzk/cs5231/overflow/lec02-FunctionCall.pdf) for more info on memory addresses

### 5/24/23

- started working on the part of project that shows the address pointers for all the functions in a file
	- Similar to [this](https://manpages.ubuntu.com/manpages/bionic/man1/readelf.1.html)

### 5/25/23

- made function that shows address pointers by running terminal comands
	- might change it later to not use terminal commands
		- found this research for if I want to change it later
		- https://www.geeksforgeeks.org/address-function-c-cpp/
		- https://stackoverflow.com/questions/21260735/how-to-invoke-function-from-external-c-file-in-c

### 5/26/23

- was absent
- started research on override-return function
	- mainly just ran buffer overflow attacks to get used to overriding the return manually

### 5/30/23

- finalized the function finding part of our project

### 5/31/23

- made draft of override-return, need to test it more.

### 6/1/23

- added override-return and help functions.
- worked on presentation with Salaj
- made drafts of homework files for attacking


## Salaj Rijal

### 05/18/23
- watched videos to gain general knowledge on buffer overflows
	- https://www.youtube.com/watch?v=1S0aBV-Waeo

### 05/19/23
- was absent (AP Exam)

### 05/22/23
- was absent (sick)
- worked on PRESENTATION.md
- read/watched these resources
	- https://www.youtube.com/watch?v=YVlTDPhTA9U
	- https://www.youtube.com/watch?v=hJ8IwyhqzD4
	- https://www.youtube.com/watch?v=fjMrDDj47E8
	- https://www.youtube.com/watch?v=TuI2HyG8-iI
	- https://www.youtube.com/watch?v=hJ8IwyhqzD4&t=8s
	- https://www.rapid7.com/blog/post/2019/02/19/stack-based-buffer-overflow-attacks-what-you-need-to-know/
	- https://www.youtube.com/watch?v=eg0gULifHFI

### 05/23/23
- got 32 bit buffer overflow attack to work
- read this article: https://medium.com/@buff3r/basic-buffer-overflow-on-64-bit-architecture-3fb74bab3558
- outlined features that our app will have
- created template for tool src files

### 05/24/23
- researched how ptrace works
	- https://www.linuxjournal.com/article/6210
	- https://man7.org/linux/man-pages/man2/ptrace.2.html
- created basic program that can view the eip of a process
- created template for tool's src files

### 05/25/23
- started work on the finding offset part of our tool
- created a projected API in README.md

### 05/26/23
- tested out ptrace and tried to figure out how it works
- added on to PRESENTATION.md
- watched https://www.youtube.com/watch?v=SajNnjeHOWI to understand how to approach finding offset (will use pattern generation)

### 05/29/23
- continued work on accessing return address of another program using ptrace

### 05/30/23
- researched ptrace more (its very complicated)
- researched pattern matching

## 05/31/23
- made the makefile
- integrated all the different functions

### 06/1/23
- worked on the presentation and homework files
- finished code obfuscation (realized that PTRACE wont work so went with terminal command and pattern generation option)
