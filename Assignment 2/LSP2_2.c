#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0, iRet = 0;
    char Fname[100] = {'\0'};
    char Buffer[100] = {'\0'};

    printf("Enter the name of file : \n");
    scanf("%s",Fname);

    printf("Enter string to write in file : \n");
    scanf(" %[^\n]",Buffer);

    fd = open(Fname,O_RDWR | O_APPEND | O_CREAT,0777);

    if(fd == -1)
    {
        printf("There is no such file\n");
        perror("Error while opening file\n");
    }
    else
    {
        printf("File succesfully opened\n");
    }

    iRet = write(fd,Buffer,strlen(Buffer));

    if (iRet == -1)
    { 
        perror("Write error");
    }
    else
    { 
        printf("Bytes written: %d\n", iRet);
    }


    close(fd);

    return 0;
}