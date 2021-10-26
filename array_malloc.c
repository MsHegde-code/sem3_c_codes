#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,*ptr;
    printf("enter the number of elements in the array\n");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int)); //memory allocation function is used to avoid unnecessary storing of memory 
    printf("enter the array elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",ptr+i);//(ptr+i) is used to increment the ptr variable to next data allocation
    }
    printf("the entered elements are:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",*(ptr+i));//*(ptr+i) is used to access the data from the pointer variable
    }
    return 0;
    
}