#include <stdio.h>
#include <dirent.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char dir[100] = {"\0"};
    char path[100] = {"\0"};
    char largest[100] = {"\0"};

    DIR *dp = NULL;

    struct dirent *ptr;
    struct stat sobj;

    long iRet = 0;

    printf("Enter directory name: ");
    scanf("%s", dir);

    dp = opendir(dir);

    if (dp == NULL)
    {
        perror("opendir error");
        return 1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        snprintf(path, sizeof(path), "%s/%s", dir, ptr->d_name);

        if(lstat(path, &sobj) == -1)
        { 
            continue;
        }

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > iRet)
            {
                iRet = sobj.st_size;
                strcpy(largest, ptr->d_name);
            }
        }
    }

    closedir(dp);

    if (iRet > 0)
    {
        printf("Largest file: %s\n", largest);
        printf("Size: %ld bytes\n", iRet);
    }
    else
    { 
        printf("No regular files found\n");
    }

    return 0;
}
