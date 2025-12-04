#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(char *s)
{
    int len = ft_strlen(s);
    char *res = malloc(len + 1);
    if (!res)
        return (NULL);
    int i = 0;
    while (s[i])
    {
        res[i] = s[i];
        i++;
    }
    res[i] = 0;
    return (res);
}

int ft_strchr(char *s, char c)
{
    int i = 0;
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
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *res = malloc(len1 + len2 + 1);
    if (!res)
        return (NULL);
    int i = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        res[len1 + i] = s2[i];
        i++;
    }
    res[len1 + len2] = 0;
    return(res);
}

char *read_til_nl(char *remain, int fd)
{
    char buf[BUFFER_SIZE + 1];
    char *result;
    char *temp;

    result = ft_strdup(remain);
    if (!result)
        return (NULL);
    int bytes = 1;
    while(!ft_strchr(result, '\n') && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = 0;
        temp = result;
        result = ft_strjoin(temp, buf);
        if (!result)
        {
            free(temp);
            return(NULL);
        }
        free(temp);
    }
    if (result[0] == '\0' && bytes == 0)
    {
        return (free(result), NULL);
    }
    return (result);
}

char *extract_line(char *buffer)
{
    if (!buffer || !buffer[0])
        return (NULL);
    int len = 0;
    while (buffer[len] && buffer[len] != '\n')
        len++;
    if (buffer[len] == '\n')
        len++;
    char *line = malloc(len + 1);
    if (!line)
        return (NULL);
    int i = 0;
    while (i < len)
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

void new_remain(char *remain, char *buffer)
{
    if (!buffer || !buffer[0])
        return; 
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

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    static char remain[BUFFER_SIZE + 1];
    char *buffer = read_til_nl(remain, fd);
    if (!buffer)
    {
        remain[0] = 0;
        return (NULL);
    }

    if (buffer[0] == '\0')
    {
        free(buffer);
        remain[0] = 0;
        return NULL;
    }
    char *line = extract_line(buffer);
    if (!line)
    {
        free(buffer);
        remain[0] = 0;
        return (NULL);
    }
    new_remain(remain, buffer);
    free(buffer);
    return (line);
}


// int main (int ac, char **av)
// {
//     // int fd = open(stdin, O_RDONLY);
//     // if (fd < 0)
//     //     return 1;
//     char *line1 = get_next_line(0);
//     char *line2 = get_next_line(0);
//     printf("line: %s", line1);
//     printf("line: %s", line2);
//     free(line1);
//     free(line2);
//     close(0);
//     return (0);
// }
