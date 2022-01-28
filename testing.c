#include<stdio.h>
void main(){
    int a=10,c=5,b;
    b=a++;
    c+=b++;
    printf("A=%d\nB=%d\nC=%d\n",a,b,c);
}