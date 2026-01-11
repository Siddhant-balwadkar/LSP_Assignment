#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int fd = 0;
    char filename[100] = {'\0'};

    printf("Enter the name of file : ");
    scanf("%s",filename);

    fd = open(filename,O_RDONLY | O_CREAT);

    if(fd == -1)
    {
        perror("Error while opening the file\n");
        return -1;
    }
    else
    {
        printf("Successfully file opened\n");
        printf("Returned File Descriptor : %d\n",fd);
    }

    close(fd);

    return 0;
}