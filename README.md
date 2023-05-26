## Features that Our Tool Will Have
- find functions in a source file w/ their return address pointers
	- also be able to examine strings
- find the offset for the bufferoverflow using fuzzing
- allow the user to construct a payload that they will input into the buffer
	- for now we will focus on ret2win attacks
	- if we have time we will do custom payload injection

## API
```./tool --help```

```./tool find-offset <prgm>```
Find the offset for when you start overriding the pointer

```./tool override-return <prgm> <offset> <new-return-address>```
Use this to override the return address and modify it to a new one (most likely will be used in function redirect attack)

```./tool list-functions <prgm>```
List all the functions and addresses

### EXTRA

```./tool list-strings <prgm>```
List all the strings in a fil

```./tool custom-payload <prgm> <tbd>``` 
Attack where you can input your own script and 