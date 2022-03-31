# LEVEL 00

* decompile the binary
    ```c
        int main() {
            int var;
            ...
            scanf("%d", var);
            if (0x149c == var)
                system("/bin/sh");
            else
                puts("\nInvalid Password!");
        }
    ```
    - the binary read from input a number
    - compare this number with '0x149c' == 5276
    - if equal do system("/bin/sh")
    - else print("failed")
    ___

* exec bin
    - write 5276 -> get sh prompt
    - cat /home/users/level01/.pass -> flag
    