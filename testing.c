#include<stdio.h>
#include<stdlib.h>
#define max 5
int top=-1,i;
char stk[max];
void push(char str){
    if(top==max){
        printf("stack overflow\n");
    }
    else{
        stk[++top]=str;
        printf("entered string is %s",str);
    }
}
void display(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        printf("entered sting is:\n");
        for (size_t i = 0; i <= top; i++)
        {
            printf("%s",stk[i]);
        }
        printf("\n");
    }
}
void pali(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        char rev[max];int len=top,flag=0;
        printf("reverse string is:\n");
        while(len>=0){
            rev[i++]=stk[len--];
        }
        for (size_t j = 0; j <= top; j++)
        {
            printf("%s",rev[j]);
        }
        for (size_t i = 0; i <= top; i++)
        {
            if(rev[i]!=stk[i]){
                flag=1;
                break;
            }
        }
        if(flag==0)     printf("it is a palindrome\n");
        else    printf("it is not a palindrome\n");
    }
}
int main(){
    char str[max];int ch;
    while(1){
        printf("enter the choice\n1.push\n2.pali\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the string\n");
                    scanf("%s",str);
                    push(str);
                    break;
            case 2: pali();
                    break;
            case 3: display();
                    break;
            default: printf("exiting\n");
                     exit(0);
                     break;
        }
        return 0;
    }

    
}