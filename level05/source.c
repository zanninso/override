#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main() {
    int index;
    char input[100];

    index = 0;
    fgets(input, 0x64, stdin);
    index = 0;
    while(index < strlen(input))
    {
        if (input[index] > '@' && input[index] <= 'Z')
        {
           input[index] ^= 0x20;
        }
        index++;
    }
    printf(input);
    exit(0);
}
