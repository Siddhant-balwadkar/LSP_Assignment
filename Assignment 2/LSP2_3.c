#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>


int main()
{
    DIR *dp = NULL;
    char dir[100] = {"\0"};
    struct dirent *ptr = NULL;

    printf("Enter the name of directory : \n");
    scanf("%s",dir);

    dp = opendir(dir);

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        printf("directory succesfily opended\n");
    }

    while((ptr = readdir(dp)) != NULL)
    { 
        if(strcmp(ptr->d_name,".") != 0 && strcmp(ptr->d_name,"..") != 0)
        { 
            printf("File name : %s\n",ptr->d_name);
        }
    }

    return 0;
}