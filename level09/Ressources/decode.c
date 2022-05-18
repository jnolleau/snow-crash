#include "unistd.h"
#include "stdio.h"
#include "fcntl.h"

void decode_pw(char *buf)
{
    int i = 0;

    while (buf[i])
    {
        buf[i] = buf[i] - i;
        i++;
    }
}


int main(int ac, char **av)
{
    int fd = -1;
    char buf[64];
    int ret = 0;

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            write(2, "FDERROR", 7);
        else
        {
            ret = read(fd, buf, 63);
            buf[ret] = '\0';
        }
        printf("Encode pw: %s", buf);
        decode_pw(buf);
        printf("Decoded pw: %s", buf);

    }
    else
        printf("Need one arg !");
}