#include<stdio.h>
#include<stdlib.h>
typedef struct dll{
        int info;
        struct dll *next,*prev;
}node;
node *start=NULL,*head;
node* create(){
        node *new;
        new=(node*)malloc(sizeof(node));
        printf("enter the info\n" );
        scanf("%d",&new->info );
        new->next=new;
        new->prev=new;
        return new;
}
void insert_rear(){
        node *new,*temp=start;
        new=create();
        if (start==NULL) {
                head=(node*)malloc(sizeof(node));
                head->next=head;
                head->prev=head;
                head->info=0;
                start=new;
                new->next=head;
                new->prev=head;
                head->next=new;
                head->prev=new;
                (head->info)++;
                return;
        }
        if (start->next==head) {
                start->next=new;
                new->next=head;
                new->prev=start;
                head->prev=new;
                (head->info)++;
                return;
        }
        while(temp->next!=head)
                temp=temp->next;
        temp->next=new;
        new->prev=temp;
        new->next=head;
        head->prev=new;
        (head->info)++;
}
void insert_front(){
        node *new;
        new=create();
        if(start==NULL){
                head=(node*)malloc(sizeof(node));
                head->next=head;
                head->prev=head;
                head->info=0;
                start=new;
                new->next=head;
                new->prev=head;
                head->next=new;
                head->prev=new;
                (head->info)++;
                return;
        }
        if(start->prev==head){
                node *temp=start;
                temp->prev=new;
                new->next=temp;
                new->prev=head;
                head->next=new;
                head->prev=temp;
                start=new;
                (head->info)++;
                return;
        }
}
void delete_front(){
        node *temp=start;
        if(start==NULL || (head->info)==0){
                printf("list is empty\n");
                return;
        }
        if(start->next==head){
                printf("deleted item is %d\n",start->info );
                head->info=0;
                free(temp);
                start=NULL;
                return;
        }
        printf("deleted item is %d\n",temp->info );
        start=start->next;
        start->prev=head;
        head->next=start;
        temp=NULL;
        free(temp);
        (head->info)--;
}
void delete_rear(){
        node *temp=start,*backnode;
        if(start==NULL || (head->info)==0){
                printf("list is empty\n");
                return;
        }
        if(start->next==head){
                printf("deleted item is %d\n",start->info );
                head->info=0;
                free(temp);
                start=NULL;
                return;
        }
        while(temp->next!=head){
                backnode=temp;
                temp=temp->next;
        }
        printf("deleted item is %d\n",temp->info );
        backnode->next=head;
        head->prev=backnode;
        (head->info)--;
        temp=NULL;
        free(temp);
}
void display(){
        node *temp=start;
        if(start==NULL || (head->info)==0){
                printf("list is empty\n");
                return;
        }
        if(start->next==head){
                printf("element is %d\n",start->info );
                printf("number of node : %d\n",head->info );
                printf("node address:%p\tnext address:%p\tprev address:%p\n",start,start->next,start->prev );
                return;
        }
        printf("elements are:\n" );
        while(temp->next!=head){
                printf("%d\t",temp->info );
                printf("node address:%p\tnext address:%p\tprev address:%p\n",temp,temp->next,temp->prev );
                temp=temp->next;
        }
        printf("%d\t",temp->info );
        printf("node address:%p\tnext address:%p\tprev address:%p\n",temp,temp->next,temp->prev );
        printf("number of nodes: %d\n",head->info );
}
void main(){
        int ch;
        while (1) {
                printf("enter the choice\n1.insert rear\n2.insert front\n3.delete rear\n4.delete front\n5.display\n6.exit\n");
                scanf("%d",&ch );
                switch (ch) {
                        case 1: insert_rear();
                                break;
                        case 2: insert_front();
                                break;
                        case 3: delete_rear();
                                break;
                        case 4: delete_front();
                                break;
                        case 5: display();
                                break;
                        default: exit(0);
                }
        }
}
