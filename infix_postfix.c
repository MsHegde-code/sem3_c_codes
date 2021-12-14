#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stk[100],opr;int top=-1;
void push(char opr){
    stk[++top]=opr;
}
char pop(){
    return stk[top--];
}
int precedence(char opr){
    if(opr=='^'||opr=='%')  return 4;
    if(opr=='*'||opr=='/')  return 3;
    if(opr=='+'||opr=='-')  return 2;
    if(opr=='#'||opr=='(')  return 1;
}
int main(){
    char infix[100],postfix[100];int j=0;
    printf("enter a valid infix expression\n");
    scanf("%s",infix);
    push('#');
    for (size_t i = 0; i < infix[i]!='\0'; i++)
    {
        if(infix[i]=='('){  
        push('(');
        }
        else if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            while(stk[top]!='('){
            postfix[j++]=pop();
            }
            pop();
        }
        else{
            if(precedence(stk[top])>=precedence(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }   
    }
    while(stk[top]!='#')
        postfix[j++]=pop();
        postfix[j++]='\0';
    printf("infix:%s\n",infix);
    printf("postfix:%s\n",postfix);
    return 0;
}