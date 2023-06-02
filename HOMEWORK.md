# HOMEWORK
Submit a text file with your asnwers on Google Classroom. Each part has their own program. To compile the programs you must run the following command: <br>
```./compile-vulnerable.sh <prgrm-name> <output-file-name>```

**NOTE:** You should do the homework on the lab machines (via ssh). As of right now, only lab machines 19 & 20 have `gcc-multilib` installed, so you should do the homework on them. The ssh-ip is: `149.89.161.1xx`
.

## Part 1: Learning the Ropes
1. Run the tool with the `--list` flag. What functions are listed?
2. Find the offset for the program using the tool. What value do you get?
3. Try overriding the return address to point to the `get_flag` function. What is the flag?

## Part 2: Challenge
1. Try to find the flag using our tool. Good luck!