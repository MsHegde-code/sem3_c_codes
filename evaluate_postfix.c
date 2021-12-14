#include<stdio.h>
#include<string.h>
#include<math.h>
char oprand,stk[20];int top=-1;
void push(char oprand){
    stk[++top]=oprand;
}
int pop(){
    return stk[top--];
}
int main(){
    char postfix[20],sym,op1,op2;
    printf("enter a valid postfix expression\n");
    scanf("%s",postfix);
    for (size_t i = 0; i < strlen(postfix); i++)
    {
        sym=postfix[i];
        switch (sym)
        {
        case '+':   op2=pop();
                    op1=pop();
                    push(op1+op2);
                    break;
        case '-':   op2=pop();
                    op1=pop();
                    push(op1-op2);
                    break;
        case '*':   op2=pop();
                    op1=pop();
                    push(op1*op2);
                    break;
        case '/':   op2=pop();
                    op1=pop();
                    push(op1/op2);
                    break;
        case '%':   op2=pop();
                    op1=pop();
                    push(op1%op2);
                    break;
        case '^':   op2=pop();
                    op1=pop();
                    push(pow(op1,op2));
                    break;
        default:    push(sym-'0');
                    break;
        }
    }
    printf("The result is %d",pop());
}