#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT 4096

int pwd_main()
{
    char buf[COUNT];

    if (getcwd(buf, COUNT) == NULL)
    {
        printf("failed geting current directory\n");
        exit(-1);
    }

    if (printf("%s\n", buf) < 0)
    {
        printf("Write failed\n");
        exit(-2);
    }

    return 0;
}