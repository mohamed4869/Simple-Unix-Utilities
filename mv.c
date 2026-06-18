#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mv_main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("%s source_file destination_file\n", argv[0]);
        exit(-1);
    }

    if (rename(argv[1], argv[2]) < 0)
    {
        printf("could not move the file\n");
        exit(-2);
    }

    return 0;
}