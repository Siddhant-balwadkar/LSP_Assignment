#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

int main()
{
    DIR *dp = NULL;
    char dir[100] = {"\0"};
    char path[100] = {"\0"};
    struct dirent *ptr = NULL;
    struct stat sobj;

    printf("Enter the name of directory : \n");
    scanf("%s",dir);

    dp = opendir(dir);

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    else
    {
        printf("directory succesfily opended\n");
    

        while((ptr = readdir(dp)) != NULL)
        {
            snprintf(path, sizeof(path), "%s/%s", dir, ptr->d_name);

            if(lstat(path,&sobj) == -1)
            {
                continue;
            }   
                printf("%s : ",ptr->d_name);
                
                
                if (S_ISREG(sobj.st_mode))
                {     
                    printf("Regular File\n");
                }
                else if (S_ISDIR(sobj.st_mode))
                {
                    printf("Directory\n");
                }
                else if (S_ISLNK(sobj.st_mode))
                {
                    printf("Symbolic Link\n");
                }
                else if (S_ISFIFO(sobj.st_mode))
                {
                    printf("FIFO\n");
                }
                else if (S_ISSOCK(sobj.st_mode))
                {   
                    printf("Socket\n");
                }
                else if (S_ISCHR(sobj.st_mode))
                {   
                    printf("Character Device\n");
                }
                else if (S_ISBLK(sobj.st_mode)) 
                {
                    printf("Block Device\n");
                }
                
            }
        }

    closedir(dp);
    
    return 0;
}