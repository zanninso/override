#include <stdio.h>
#include <stdlib.h>

int main() {
    int var;
    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", var);
    if (0x149c == var) {
        printf("autheticated!:");
        system("/bin/sh");
    } else
        puts("\nInvalid Password!");
}