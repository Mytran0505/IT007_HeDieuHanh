#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/wait.h>

int loop=1; 

void on_sigint()
{
	printf("You are press CTRL+C! Goodbye"); 
	loop=0;
}

int main()
{
	loop=1; 
	printf("\nWelcome to IT007, I am 20520322!\n"); 
	system("gedit abcd.txt"); 
	signal(SIGINT,on_sigint); 
	while(loop){} 
	return 0;
}
