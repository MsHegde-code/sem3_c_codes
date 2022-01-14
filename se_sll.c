#include<stdio.h>
#include<stdlib.h>
typedef struct sll{
    int info;
    struct sll *next;
}node;
node *start=NULL;
node* createnode(){//use node *create because the return type is a node address
    node *new;
    new=(node*)malloc(sizeof(node));
    printf("enter the info\n");
    scanf("%d",&new->info);
    new->next=NULL;
    return new;
}
void insert_rear(){
    node *new,*temp=start;
    new=createnode();
    if(start==NULL){
        start=new;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new;
}
void delete_rear(){
    node *temp=start,*prev;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    if(start->next==NULL){
        printf("the deleted item is: %d\n",start->info);
        start=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        }
        printf("the deleted item is: %d\n",temp->info);
        prev->next=NULL;
        free(temp);
        return;
}
void display(){
    node *temp=start;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    printf("the entered elements are:\t");
    while(temp!=NULL){
        printf("\n%d\taddress: %u\n",temp->info,temp);
        temp=temp->next;
    }
}
void main(){
int ch;
    while(1){
        printf("\nenter the choice\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:     insert_rear();
                        break;
            case 2:     delete_rear();
                        break;
            case 3:     display();
                        break;
            default:    exit(0);
                        break;
        }
    }
}