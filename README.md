# TEAM ROCKET 🚀: Sunil Parab & Salaj Rijal

## Links
[HOMEWORK](HOMEWORK.md)<br>
[PRESENTATION](PRESENTATION.md)


## How to Build
To build our tool, first clone the repo and then run this command:

```make tool```

## API
```./tool --help```<br>
Short guide on how to use our tool (sort of like this api)

```./tool --list <prgm>```<br>
List all the functions and their addresses for a program

```./tool --offset <prgm>```<br>
Find the offset for when you start overriding the return address

```./tool --override <prgm> <return-address> <offset>```<br>
Use this to override the return address and modify it to a new one

## EXTRA (we did not have time for this)
```./tool --strings <prgm>```<br>
List all the strings in a file

```./tool --paylaod <prgm> <payload>```<br>
Inject your own custom payload into a program and run it
