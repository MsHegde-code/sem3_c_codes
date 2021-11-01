#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,*data,temp,high,low,mid,key;
    printf("enter the array size\n");
    scanf("%d",&n);
    data=(int*)malloc(n*sizeof(int));//dynamic memory alloc
    printf("enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",(data+i));//input
    }
    for(i=0;i<n;i++){
        //elements sorting in ascending order
        for(j=0;j<n;j++){
        if(data[j]>data[j+1]){
            temp=data[j];
            data[j]=data[j+1];
            data[j+1]=temp;
        }
        }
    }
    printf("the sorted elements are:\n");//print sorted ele
    for(i=0;i<n;i++){
        printf("%d\t",*(data+i));
    }
    printf("\n");
    low=0;//binary search
    high=n-1;
    mid=(high+low)/2;
    printf("binary search\nenter the key element\n");
    scanf("%d",&key);
    while(low<=high){
        if(key<data[mid])
            high=mid-1;
        else if(key>data[mid])
            low=mid+1;
        else if(key==data[mid]){
            printf("%d is found at %d position\n",key,mid);
            return 0;}
        else printf("%d is not found in the array\n",key);
        }
    
    free(data);
    return 0;
}