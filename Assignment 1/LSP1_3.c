#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int flags = 0;
    char Mode[100] = {'\0'};
    char filename[100] = {'\0'};

    printf("Enter file name : \n");
    scanf("%s",filename);

    printf("Enter mode (read / write / execute): \n");
    scanf("%s",Mode);

    if(strcmp(Mode,"read") == 0)
    {
        flags = R_OK;
    }
    else if(strcmp(Mode,"write") == 0)
    {
        flags = W_OK;
    }    
    else if(strcmp(Mode,"execute") == 0)
    {
        flags = X_OK;
    }
    else
    {
        printf("Invalid Mode\n"); 
        return 1;
    }

    if(access(filename,flags) == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not Accessible\n");
        perror("Reason");
    }   

    return 0;   
}