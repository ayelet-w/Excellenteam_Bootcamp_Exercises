#include <stdio.h>
#include <string.h>
void my_strcat(char tgt[],char src[])
{
	char * res=tgt+strlen(tgt);
	strcpy(res,src);
}
int main()
{
	char s1[]="Ayelet";
	char s2[]="w";
	my_strcat(s1,s2);
	printf("%s\n",s1);
	
	return 0;
}
