# this file will compile $1 using gcc so that it is vulnerable to a buffer overflow attack. Specity $2 if you want a specific name for the output file

if [ "$2" ]
then
	gcc -m32 $1 -o $2 -fno-stack-protector -g -z execstack -no-pie
else
	gcc -m32 $1 -o a.out -fno-stack-protector -g -z execstack -no-pie
fi
