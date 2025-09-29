#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_strchr(const char *s, char c)
{
    int i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (NULL);
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *result = malloc (len1 + len2 + 1);
    int i = 0;

    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        result[len1 + i] = s2[i];
        i++;
    }
    result[len1 + len2] = 0;
    return (result);
}

char *read_until_nl(int fd, char *remain)
{
    char buf[BUFFER_SIZE + 1];
    int bytes;
    char *tmp;
    char *result;

    result = remain;
    while(!ft_strchr(result, '\n') && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = 0;
        tmp = result;
        result = ft_strjoin(tmp, buf);
        if (!result)
            return (NULL);
    }
    return (result);
}

void new_remain(char *remain, char *buffer)
{
    int i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    int j = 0;
    while (buffer[i] && j < BUFFER_SIZE)
        remain[j++] = buffer[i++];
    remain[j] = 0;
}

char *extract_line(char *buffer)
{
    char *line;
    int len = 0;
    if (!buffer || !buffer[0])
        return (NULL);
    while (buffer[len] && buffer[len] != '\n')
        len++;
    if (buffer[len] == '\n')
        len++;
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    int i = -1;
    while (++i < len)
        line[i] = buffer[i];
    line[i] = 0;
    return (line);
}

char *get_next_line(int fd)
{
    static char remain[BUFFER_SIZE + 1];
    char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_until_nl(fd, remain);
    if (!buffer)
        return (NULL);
    new_remain(remain, buffer);
    line = extract_line(buffer);
    if (!line)
    {
        free(buffer);
        return (NULL);
    }
    free(buffer);
    return (line);
}

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("file.txt", O_RDONLY);
//     if (fd < 0)
//         return (1);
//     line = get_next_line(fd);
//     printf("line = %s", line);
//     free(line);
//     close(fd);
//     return (0);
// }