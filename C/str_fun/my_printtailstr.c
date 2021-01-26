#include<stdio.h>

void printFromTail(const char src[])//not work!!
{ 	
	char * const start = (char * const )src;
	
	while(*src++)
	
	--src;
	
	while(src >= start) 
		printf("%s\n",--src);
	
}
void printFromTailRec(const char src[])
{ 	
	if(*src)
	{
		printFromTailRec(src+1);
		
		printf("%s\n",src);
	}
	
}
int main()
{
	char s1[]="pointers";
	printFromTailRec(s1);
	printFromTail(s1);
	
	return 0;
}

