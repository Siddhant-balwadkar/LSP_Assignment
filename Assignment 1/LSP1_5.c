#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char filename[100] = {'\0'};
    char Buffer[100] = {'\0'};
    int N = 0, iRet = 0, fd = 0;

    printf("Enter file name : \n");
    scanf("%s",filename);

    printf("Enter number of bytes to read : \n");
    scanf("%d",&N);

    fd = open(filename, O_RDONLY);

    if(fd == -1)
    {
        perror("Error while opening file\n");
        return 1;
    }

    iRet = read(fd,Buffer,N);

    if(iRet == -1)
    {
        perror("Error while reading file");
        return 1;
    }
    else
    {
        printf("Data read : %s\n",Buffer);
    }

    close(fd);

    return 0;
}