	

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd = open("link.txt",O_CREAT|O_WRONLY);

	link("link.txt","clink.txt");

	write(fd,"jyotirmay sethi",strlen("jyotirmay sethi"));

	return(0);

}

:

