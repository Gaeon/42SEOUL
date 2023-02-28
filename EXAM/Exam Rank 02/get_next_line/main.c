#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd;

    fd=open("file.txt",O_RDONLY);
    while (1)
    {
        char *str = get_next_line(fd);
        if (str)
            printf("%s", str);
        else
            break;
    }
    return (0);
}