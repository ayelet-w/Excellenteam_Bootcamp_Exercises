#include <stdio.h>
#include <stdlib.h>
#define SIZEOF_V(type) (char *)(&type+1)-(char*)(&type) 
#define SIZEOF_T(type) (char*) (&(((type *)0)[2])) - (char *)(&(((type *)0)[1]))
/*==(char*)(&(((int *)0[2])==(char*)(&(*((int *)0+2))) */
int main()
{
        int x=3;
        long y;
        char c;
        printf("--------variables-------\n");
	printf("size of int: %ld \n",SIZEOF_V(x));
	printf("size of long: %ld \n",SIZEOF_V(y));
	printf("size of char: %ld \n",SIZEOF_V(c));
	printf("--------types-------\n");
	printf("size of int: %ld\n",SIZEOF_T(int));
	printf("size of long: %ld\n",SIZEOF_T(long));
	printf("size of char: %ld\n",SIZEOF_T(char));
	
	return 0;
}
