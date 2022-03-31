# LEVEL 3

* decompile the binary:
    ```c
    void decrypt(int password) {
        char hash[17] = "Q}|u`sfg~sf{}|a3";
        int decrypt_size = 0;

        while (decrypt_size < strlen(hash))
        {
            hash[decrypt_size] = hash[decrypt_size] ^ password;
            decrypt_size++;
        }
        if (strncmp("Congratulations!", hash, 17) == 0)
            system("/bin/sh");
        ...
    }

    void test(int in_pass, int pass) {
        unsigned int res = (pass - in_pass);
        if (res <= 21)
            decrypt(res);
        else
            decrypt(rand());
        return;
    }

    int main() {
        int password;
        ...
        scanf("%d", &password);
        test(password, 0x1337d00d);
    }
    ```
    - read number from input
    - sub this number from 0x1337d00d save result
    - compare result: result <= '0x15'
    - if true: call decrypt(result)
    - decrypt:
        - decrypt "Q}|u`sfg~sf{}|a3" with the result save it in hash.
        - compare hash == "Congratulations!"
        - if true: system("/bin/sh")
        - else print("error")

    ___

* prepare:
    to call decrypt with the result we need to send a value with  0 <= 0x1337d00d - x <= 21
    so we have 21 number that make it easy to try to decrypt ``Q}|u`sfg~sf{}|a3`` with all the 21 number
    then we found that 18 give us the result that we want.
    > <b>0x1337d00d - 18 == 322424827</b>
    
    ___

* exec bin:
    - write 322424827 -> get sh prompt
    - cat /home/users/level04/.pass -> flag
