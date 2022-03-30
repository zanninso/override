#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(FILE *log_file, char* msg, char* file)
{
    char log_str[264];

    strcpy(log_str, msg);
    snprintf(log_str + strlen(log_str), 254 - strlen(log_str), file);
    log_str[strcspn(log_str, "\n")] = 0;
    fprintf(log_file, "LOG: %s\n", log_str);
}

int main(int ac, char **av)
{
    FILE *log_file;
    FILE *file;
    char c = -1;
    int fd = -1;
    char backups[99] = "./backups/";

    if (ac != 2)
        print("Usage: %s filename\n", av[0]);
    log_file = fopen("./backups/.log", "w");
    if (log_file == NULL)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    log_wrapper(log_file, "Starting back up: ", av[1]);
    file = fopen(av[1], "r");
    if (file == NULL)
    {
        printf("ERROR: Failed to open %s\n", av[1]);
        exit(1);
    }
    strncat(backups, av[1], 99 - strlen(backups));
    fd = open(backups, 0xc1, 0660);
    if (fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
        exit(1);
    }
    while ((c = fgetc(file)) != -1)
        write(fd, &c, 1);
    log_wrapper(log_file, "Finished back up ", av[1]);
    fclose(file);
    close(fd);
    return (0);
}
