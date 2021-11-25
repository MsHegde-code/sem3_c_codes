#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stk[100],opr;int top=-1;
void push(char opr){
    stk[++top]=opr;
}
int pop(){
    return stk[top--];
}
int precd(char opr){
    if(opr=='^'||opr=='%')
        return 4;
    else if(opr=='/'||opr=='*')
        return 3;
    else if(opr=='+'||opr=='-')
        return 2;
    else if(opr=='#'||opr=='(')
        return 1;
}
int main(){
    char infix[100],postfix[100];int j,i;
    printf("enter the valid infix expression\n");
    scanf("%s",infix);
    push('#');
    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='(')
            push('(');
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
            while(precd(stk[top])>=precd(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(stk[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    printf("infix=%s\n",infix);
    printf("postfix=%s\n",postfix);
    return 0;
}