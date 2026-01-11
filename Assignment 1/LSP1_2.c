#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    int flags = 0;
    char filename[100] = {'\0'};
    char Mode[100] = {'\0'};

    printf("Enter file name : ");
    scanf("%s",filename);

    printf("Enter mode (R / W / RW / A) : ");
    scanf("%s",Mode);

    if(strcmp(Mode, "R") == 0)
    {
        flags = O_RDONLY;
    }
    else if(strcmp(Mode,"W") == 0)
    {
        flags = O_WRONLY | O_CREAT;
    }
    else if(strcmp(Mode,"RW") == 0)
    {
        flags = O_RDWR | O_CREAT;
    }
    else if(strcmp(Mode,"A") == 0)
    {
        flags = O_APPEND | O_CREAT | O_WRONLY;
    }
    else
    {
        printf("Invalid mode\n");
        return -1;
    }

    fd = open(filename,flags,0777);
    
    if(fd == -1)
    {
        perror("Error while opening file\n");
        return -1;
    }

    printf("Succesfully opened file\n");
    printf("Fd of file is : %d\n",fd);

    
    close(fd);

    return 0;
}