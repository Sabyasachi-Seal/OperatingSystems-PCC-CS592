#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char str1[50],str2[50],result[50];
    
    int fd1 = open("./myfifo1",O_RDONLY);
    perror("open");
    int fd2 = open("./myfifo2",O_WRONLY);
    perror("open");

    read(fd1,str1,sizeof(str1));
    read(fd1,str2,sizeof(str2));

    if(!strcmp(str1,str2))
        strcpy(result,"SAME");
    else
        strcpy(result,"NOT SAME");

    write(fd2,result,strlen(result) + 1);
    return 0;
}
