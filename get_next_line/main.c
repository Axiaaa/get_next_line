
#include "get_next_line.h"
#include <fcntl.h>

void main()
{
    int fd = open("test.txt", O_RDONLY);
    char *a = get_next_line(fd);
    char *b = get_next_line(fd);
    char *c = get_next_line(fd);
    
    printf("%s", a);
    printf("%s", b);
    printf("%s", c);
    free_strs(&a, &b, &c);
}