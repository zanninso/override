#include "stdio.h"
#include "string.h"

void set_username(char *username)
{
    char input[140];
    int idx;

    bzero(input, 16);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(input,128,stdin);
    idx = 0;
    while (idx <= 40 && input[idx] != 0)
    {
        (username + 140)[idx] = input[idx];
        idx++;
    }
    printf(">: Welcome, %s", username + 140, username + 140);
}

void set_msg(char *username)
{
    char input[1024];

    bzero(input, 128);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(input, 1024, stdin);
    strncpy(username, input, ((int*)username)[45]);
}

void handle_msg()
{
    char username[180] = {0};
    int var = 140;
    set_username(username);
    set_msg(username);
    puts(">: Msg sent!");
}

int main()
{
    puts("--------------------------------------------\n\
          |   ~Welcome to l33t-m$n ~    v1337        |\n\
          --------------------------------------------");
    handle_msg();
}
