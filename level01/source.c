#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char in_user_name[256];
char *user = "dat_wil";
char *pass = "admin";

int verify_user_name() {
    puts("verifying username....\n");
    return strncmp(user, in_user_name, 7);
}

int verify_user_pass(char *password) {
    return strncmp(pass, password, 5);
}

int main() {
    int error;
    char password[64];
    memset(password, 0, 16);
    error = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    print("Enter Username: ");
    fgets(in_user_name, 0x100, stdin);
    error = verify_user_name();
    if (error == 0) {
        puts("Enter Password: ");
        fgets(password, 0x64, stdin);
        error = verify_user_pass(password);
        puts("nope, incorrect password...\n");
    }
    else
        puts("nope, incorrect username...\n");
}
