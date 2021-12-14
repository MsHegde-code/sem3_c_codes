//tower of hanoi 
#include<stdio.h>
#include<stdlib.h>
int n;char source,aux,destination;
void tower(int n,char source,char aux,char destination){
    if(n==1)
    printf("move 1 disk from %c to %c\n",source,destination);
    else{
        tower(n-1,source,destination,aux);
        printf("move %d disk from %c to %c\n",n,source,destination);
        tower(n-1,aux,source,destination);
    }
}
int main(){
    printf("enter the number of disks\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
}