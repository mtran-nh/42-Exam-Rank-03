#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    
    char *line;
    int line_count = 0;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]", ++line_count, line);
        if (line[strlen(line) - 1] != '\n')
            printf("\\n");
        printf("\n");
        free(line);
    }
    
    printf("Total lines read: %d\n", line_count);
    close(fd);
    return 0;
}
