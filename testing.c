#include<stdio.h>
void main(){
    int c=10,i,j,k;
    for(i=1;i<=15;i++)
        for(j=i;j<=15;j++)
            for(k=j;k<=15;k++)  
                c=c+1;
    printf("ans:%d\n",c);
}