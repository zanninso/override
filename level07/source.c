#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void clear_stdin() {
    char c = 0;
    do
    {
        c = getchar();
        if (c == 0xa)
            return;
    } while (c != -1);
}

u_int32_t get_unum() {
    u_int32_t num = 0;
    fflush(stdout);
    scanf("%u", &num);
    clear_stdin();
    return num;
}

int store_number(int *data)
{
    int num = 0;
    int idx = 0;

    printf(" Number: ");
    num = get_unum();

    printf(" Index: ");
    idx = get_unum();
    if (idx % 3 != 0 && (num >> 0x18) != 0xb7)
    {
            data[idx] = num;
            return (0);
    }
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return (1);
}

int read_number(int *data)
{
    int idx;

    idx = 0;
    print(" Index: ");
    idx = get_unum();
    print(" Number at data[%u] is %u\n", idx, data[idx]);
    return 0;
}

int main(int ac, char **av, char **env)
{
    int input[25];
    int  error = 0;
    char cmd[20];
    
    memset(cmd, 0, 20);
    bzero(input, 0x64);
    while (*av != NULL)
    {
        memset(*av, 0, strlen(*av));
        av++;
    }
    while (*env != NULL)
    {
        memset(*env, 0, strlen(*env));
        env++;
    }
    puts("----------------------------------------------------\n\
    Welcome to wil's crappy number storage service!\n\
    ----------------------------------------------------\n\
    Commands:\n\
    store - store a number into the data storage\n\
    read  - read a number from the data storage\n\
    quit  - exit the program\n\
    ----------------------------------------------------\n\
    wil has reserved some storage :>\n\
    ----------------------------------------------------\n");
    while (1)
    {
        printf("Input command: ");
        error = 1;
        fgets(cmd, 0x14, stdin);
        cmd[strlen(cmd) - 1] = 0;
        if (strncmp(cmd, "store", 5) == 0)
            error = store_number(input);
        else if (strncmp(cmd, "read", 4) == 0)
            error = store_number(input);
        else if(strncmp(cmd, "quit", 4) == 0)
            return(0);
        if (error == 0) 
            print(" Completed %s command successfully\n", cmd);
        else
            printf(" Failed to do %s command\n", cmd);
        memset(cmd, 0, 20);
    }
}
