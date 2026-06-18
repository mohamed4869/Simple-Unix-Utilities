#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int echo_main(int argc, char* argv[])
{
    
    for (int i = 1; i < argc; i++)
    {
        if (printf("%s", argv[i]) < 0)
        {
            printf("Write failed\n");
            exit(-1);
        }

        if (i < argc - 1)
        {
            if (printf(" ") < 0)
            {
                printf("Write failed\n");
                exit(-2);
            }
        }
    }

    if (printf("\n") < 0)
    {
        printf("Write failed\n");
        exit(-3);
    }

    return 0;
}