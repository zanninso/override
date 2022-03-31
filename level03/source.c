#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void decrypt(int password) {
    int decrypt_size;
    int len;
    char hash[17] = "Q}|u`sfg~sf{}|a3";
    len = strlen(hash);
    decrypt_size = 0;
    while (decrypt_size < len)
    {
        hash[decrypt_size] = hash[decrypt_size] ^ password;
        decrypt_size++;
    }
    if (strncmp("Congratulations!", hash, 17) == 0)
        system("/bin/sh");
    else 
        puts("\nInvalid Password");
}

void test(int in_pass, int pass) {
    unsigned int res = (pass - in_pass);
    if (res <= 21)
    {
        goto *((res << 0x2) + 0x80489f0);// 0x80489f0 -> (&decrypt(rand()));
        {
            decrypt(res);
            goto out;
        } // repeted 15 time
    }
    else
        decrypt(rand());
    out:
    return;
}

int main() {
    int password;
    srand(time(NULL));
    puts("***********************************");
    puts("*		level03		**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &password);
    test(password, 0x1337d00d);
}
