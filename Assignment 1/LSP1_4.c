#include<stdio.h>
#include<time.h>
#include<sys/stat.h>

int main()
{
    struct stat sobj;
    int iRet = 0;
    char filename[100] = {'\0'};

    printf("Enter file name : ");
    scanf("%s",filename);

    iRet = stat(filename,&sobj);

    printf("Inode number : %lu\n",sobj.st_ino);
    printf("Hardlink count : %lu\n",sobj.st_nlink);
    printf("Size : %lu\n",sobj.st_size);
    printf("Owner UID : %d\n",sobj.st_uid);
    printf("Owner GID : %d\n",sobj.st_gid);
    printf("File type is : %d\n",sobj.st_mode);

    printf("Last Access Time : %s\n",ctime(&sobj.st_atime));
    printf("Last Modify Time : %s\n",ctime(&sobj.st_mtime));
P
    return 0;
}