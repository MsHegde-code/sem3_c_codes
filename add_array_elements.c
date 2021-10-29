#include<stdio.h>
int main(){
    int i,arr[5]={10,20,30,40,50};
    for(i=0;i<5;i++){
        arr[i]=arr[i]+1;
    }
    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }
}