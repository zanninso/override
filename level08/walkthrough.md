# LEVEL 08

* after decompiling the binary:
	- we found that it open the file given as the first argument.
		```c
		file = fopen(av[1], "r");
		```
	- it does open a file for writing by concatenating `"./backups/"` with the first
	first 89 characters from the first argument.
		```c
		strncat(backups, av[1], 99 - strlen(backups));
		fd = open(backups, 0xc1, 0660);
		```
	- then copy the contents of the first file into the second.
		```c
		while ((c = fgetc(file)) != -1)
        	write(fd, &c, 1);
		```
 
* to exploit the program:
	- inside `/tmp`, create these nested folders: `home/users/level09/`
	- also in `/tmp` create a directory named `backups` with a file inside it called `.log`
	- allow everyone to read and write to the files and directories mentioned above.
	- run the program from `/tmp` with the argument `/home/users/level09/.pass`
	- the flag should be in `/tmp/home/users/level09/.pass`
