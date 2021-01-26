#include<stdio.h>
#include<string.h>
void my_strcopy(char tgt[],const char src[])
{
	while((*tgt++ = *src++));
}
int main()
{ 
	char s1[]="pointers";
	char s2[16];
	my_strcopy(s2,s1);
	printf("%s\n",s2);
	return 0;
}
