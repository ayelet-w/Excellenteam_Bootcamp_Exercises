#include <stdio.h>

#include "VECTOR.h"


int main(){
    int num;
    Vector *v1=vectorInit();
    Vector *v = vectorCreate(5);
    printf("PUSH\n");
    vectorPush(v, 7);
    vectorPush(v, 47);
    vectorPush(v, 67);
    vectorPush(v, 87);
    vectorPrint(v);
    printf("INSERT 7 to index 3\n");
    vectorInsert(v, 7, 3);
    vectorPrint(v);
    printf("INSERT 9 to index 9\n");
    vectorInsert(v, 9, 9);
    vectorPrint(v);
    printf("INSERT 23 to index 1\n");
    vectorInsert(v, 23, 1);
    vectorPrint(v);
    printf("how much 7 digit are in vector: %d\n", (int)vectorCount(v, 7));
    printf("POP\n");
    vectorPop(v, &num);
    printf("num: %d\n",num);
    printf("REMOVE index 6\n");
    vectorRemove(v, 6, &num);
    vectorPrint(v);
    printf("the number that removed: %d\n",num);
    printf("REMOVE index 40\n");
    vectorRemove(v, 40, &num);
    vectorPrint(v);
    printf("GETELEMENT from index 2\n");
    vectorGetElement(v,2,&num);
    printf("num: %d\n",num);
    printf("SETELEMENT 3 into index 2\n");
    vectorSetElement(v,2,3);
    vectorPrint(v);
    printf("GETSIZE\n%d \n",(int)vectorGetSize(v));
    printf("GETCAPACITY\n%d \n",(int)vectorGetCapacity(v));
    vectorDestroy(&v);

    return 0;

}