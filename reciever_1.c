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

    int fd1 = open("./myfifo_super",O_RDONLY);
    perror("open");
    while(1)
    {   read(fd1,str,sizeof(str));
    puts(str);
    }
    return 0;
}
