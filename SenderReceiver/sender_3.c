#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char str[50];

    unlink("myfifo_super");

    mkfifo("myfifo_super",0777);
    perror("myfifo_super");

    int fd1 = open("myfifo_super",O_WRONLY);
    int i=0;
    for(i=1;i<=5;i++)
    {
        printf("Enter string %d: ",i);
        fgets(str,50,stdin);
        write( fd1, str, strlen(str) + 1 );
        sleep(1);
    }
    return 0;
}
