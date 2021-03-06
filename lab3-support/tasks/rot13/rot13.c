/*
 * rot13.c: ROT13 cipher test application
 *
 * Authors: shang <shang@andrew.cmu.edu>
 *          
 * Date:    9:22 0CT 10
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BLOCK 100

char caesar(char c){

	if((c >= 'A' && c <= 'M')
	|| (c >= 'a' && c <= 'm'))
	{		
		return	c + 13;
	}
	else if((c >= 'N' && c <= 'Z')
	|| (c >= 'n' && c <= 'z'))
		return	c - 13;
	return c;
}

int main(int argc, char *argv[]) {
	char buffer[BLOCK+1];
        unsigned long startTime=0;

	int i = 0, j =0, k=0, error;
	//write(STDOUT_FILENO, argc,
	for ( j=0; j< argc; j++)
	{	
		k=0;
		while(argv[j][k] != '\0')
		{
			k++;
		}		
		write(STDOUT_FILENO, argv[j], k);
		write(STDOUT_FILENO, "\n", 1);	
	}
	while(1){
                startTime = time(); 
                printf("start time %lu\n",startTime);
		error = read(STDIN_FILENO, buffer, BLOCK);
		if(error == 0)
			exit(0);	
		else if(error <0)
			exit(1);
		else{
			for(i = 0; i < error; i++)
			{
				char tmp = caesar(buffer[i]);
				buffer[i] = tmp;
			}
			//buffer[i] = '\0';
			error =  write(STDOUT_FILENO, buffer, i+1);
		
			if(error < 0)
				exit(1);
			for(i = 0; i < BLOCK; i++)
				buffer[i] = '\0';
		}
	}
	return 0;
}
