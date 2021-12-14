#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,*a;
    printf("enter the array size\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if (a==NULL)
    {
        printf("array not created\n");
        exit(0);
    }
    printf("enter the array elements:\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",(a+i));
    }
    printf("entered elements are:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t",*(a+i));
    }
    printf("\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            int swap;//logic mismatch
            swap=a[j];
            a[j]=a[i];
            a[i]=swap;
        }
        
    }
    printf("sorted elements are:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d",*(a+i));
    }
    return 0;
    
    
    
    
}