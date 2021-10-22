#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,arr[100],n,key;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the key element\n");
    scanf("%d",&key);
    for (i = 0; i < n; i++)
    {
        if(arr[i]==key)
            printf("the '%d' element is present in the array\n",key);
    }
    return 0;
}