#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly{
        int cf,px,py,pz,flag;
        struct poly *next;
}node;
node *head=NULL;
node* create(){
        node *new;
        new=(node*)malloc(sizeof(node));
        new->next=NULL;
        return new;
}
void insert(node *new){
        node *temp=head;
        if(head->next==NULL){
                head->next=new;
                return;
        }
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=new;
}
void getinfo(){
        node *new;int ch;
        do{
                new=create();
                printf("enter the coefficient\n");
                scanf("%d",&new->cf);
                printf("enter the powers of x,y,z\n");
                scanf("%d%d%d",&new->px,&new->py,&new->pz);
                insert(new);
                printf("to continue press 1 else 0\n");
                scanf("%d",&ch);
        }while(ch!=0);
}
void display(){
        node *temp=head->next;
        if(temp==NULL){
                printf("list is empty\n");
                return;
        }
        while(temp!=NULL){
                printf("%d*x^%d*y^%d*z^%d",temp->cf,temp->px,temp->py,temp->pz);
                if(temp->next!=NULL)
                        printf("+\n");
                temp=temp->next;
        }
}
void evaluate(){
        node *temp=head->next;int ans=0,x,y,z;
        printf("\nenter the values for x,y,z\n");
        scanf("%d%d%d",&x,&y,&z);
        if(head==NULL){
                printf("list not found\n");
                return;
        }
        while(temp!=NULL){
                ans=ans+(temp->cf * pow(x,temp->px) * pow(y,temp->py) * pow(z,temp->pz));
                temp=temp->next;
        }
        printf("The result is : %d\n",ans);
}
void main(){
        int ch;
        while(1){
                printf("enter the choice\n1.evaluate\n2.addition\n3.exit\n");
                scanf("%d",&ch);
                switch (ch)
                {
                case 1:
                        head=create();
                        getinfo();
                        display();
                        evaluate();
                        break;
                
                default: exit(0);
                        break;
                }
        }
}