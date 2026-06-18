#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define COUNT 4096

int cp_main(int argc, char* argv[])
{
    char buf[COUNT];

    if (argc != 3)
    {
        printf(" %s source_file destination_file\n", argv[0]);
        exit(-1);
    }

    int fd_src = open(argv[1], O_RDONLY);
    
    if (fd_src < 0)
    {
        printf("could not open source file\n");
        exit(-2);
    }

    int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    if (fd_dest < 0)
    {
        printf("could not open or create destination file\n");
        exit(-3);
    }

    int num_read;
    
    while ((num_read = read(fd_src, buf, COUNT)) > 0)
    {
        if (write(fd_dest, buf, num_read) < 0)
        {
            printf("Write failed\n");
            exit(-4);
        }
    }



    return 0;
}