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
    
    unlink("myfifo1");
    unlink("myfifo2");
    
    mkfifo("myfifo1",0777);
    perror("myfifo1");
    mkfifo("myfifo2",0777);
    perror("myfifo2");
    
    int fd1 = open("myfifo1",O_WRONLY);
    int fd2 = open("myfifo2",O_RDONLY);
    
    printf("Enter string 1: ");
    fgets(str1,50,stdin);
    printf("Enter string 2: ");
    fgets(str2,50,stdin);
    
    write( fd1, str1, strlen(str1) + 1 );
    sleep(1);
    write( fd1, str2, strlen(str2) + 1 );
    sleep(1);

    read( fd2, result, sizeof(result) );
    printf("The two strings are %s\n",result);

    return 0;
}
