# LEVEL 04

* after decompiling the binary:
	- we notice that it takes two inputs, a string and a number.
	```c
		fgets(buf, 32, stdin);
		...
		scanf("%u", &n);
	```
	- it does hash the string and check if the result is equal to the number, if they
	were equal, then a shell will prompt, otherwise the program will exit.
 
* to exploit the program:
	- we execute the program, and provide it a arbitrary string and number,
	and then we use gdb to stop the program and see the hash result.
	- we enter the found combination:
		- for the string: `"mohamed"`
		- the hash result is: `"6233785"`
---
the output looks like this:
```
***********************************
*		level06		  *
***********************************
-> Enter Login: mohamed
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6233785
Authenticated!
$
```



