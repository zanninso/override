#include "stdio.h"
#include "string.h"

void set_username(char *data)
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
        (data + 140)[idx] = input[idx];
        idx++;
    }
    printf(">: Welcome, %s", data + 140, data + 140);
}

void set_msg(char *data)
{
    char input[1024];

    bzero(input, 128);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(input, 1024, stdin);
    strncpy(data, input, ((int*)data)[45]);
}

void handle_msg()
{
    char data[180] = {0};
    int len = 140;
    set_username(data);
    set_msg(data);
    puts(">: Msg sent!");
}

int main()
{
    puts("--------------------------------------------\n\
          |   ~Welcome to l33t-m$n ~    v1337        |\n\
          --------------------------------------------");
    handle_msg();
}
