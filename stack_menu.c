#include<stdio.h>
#include<stdlib.h>
#define max 5
int top=-1,stack[max],rev[max],item;
void push(int element){
    if(top==max){
        printf("stack overflow\n");
    }
    else{
        stack[++top]=element;
        printf("the entered element is %d\n",element);
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        item=stack[top--];
        printf("the removed element is %d\n",item);
    }
}
void display(){
    printf("the entered elements are : \n");
    for (size_t i = 0; i <= top; i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
int palindrome(){
    int len=top,i=0;
    if(top==-1){
        printf("stack underflow..\n");
    }
    else{
        int flag=0;
        while(len>=0){
            rev[i++]=stack[len--];
        }
        printf("stack reversed : \n");
        for (size_t i = 0; i <= top; i++)
        {
            printf("%d\t",rev[i]);
        }
        printf("\n");
        printf("to check palindrome\n");
        for (size_t j = 0; j <= top; j++)
        {
            if(rev[j]!=stack[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("it is a palindrome\n");
        }
        else{
            printf("it is not a palindrome\n");
        }
        
    }
}
int main(){
    int choice,element;
    while(1){
        menu:printf("Enter your choice\n1.push an element\n2.pop the top element\n3.check palindrome\n4.display\n5.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter the element to be inserted\n");
                    scanf("%d",&element);
                    push(element);
                    break;
            case 2: pop();
                    break;
            case 3: palindrome();
                    break;
            case 4: display();
                    break;
            case 5: printf("exiting..\n");
                    exit(0);
                    break;
            default: printf("invalid input\n");
                     goto menu;
                     break;
        }
    }
    return 0;
}