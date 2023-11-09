#include "get_next_line.h"

void main()
{
    int fd = open("test.txt", O_RDONLY);
    char *l = get_next_line(fd);
    printf("%s", l);
    free(l);
}