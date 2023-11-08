#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//generates many characters
//argumemt will tell you how many characters will be generates
void main(int argc, char** argv){
  //printf(inside of randomgen.c);
	if(argc != 2)
		fprintf(stderr, "Error: The program expect one command-line argument which is the length of randomly generated string\n");
	int n = atoi(argv[1]);
	srand(time(NULL));
	long l = 0;
  //n number of characters
	while(l++ < n)
		putchar('a'+rand()%26);
}