#include<stdio.h>
size_t my_strlen(const char src[])
{
       size_t size=0;
	while(*src++)
	{ 	
		size++;
	}
	return size;
}
int my_strlen_imp(const char src[])
{
       char * const start = (char * const)src;
	while(*src++)

	return src - start -1;
}
int main()
{ 
	char str[]="Ayelet";
	printf("%d\n",my_strlen(str));
	printf("%d\n",my_strlen_imp(str));
	
	return 0;
}
