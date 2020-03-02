#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>


extern int errno;
int main()

{


int fd=creat("foo321.txt", O_CREAT);
printf("fd=%d\n",fd);
if (fd==-1)
{

printf("error no=%d\n",errno);
perror("programe");



}
return 0;

}