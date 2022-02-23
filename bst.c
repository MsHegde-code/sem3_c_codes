#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int info;
    struct bst *rptr,*lptr;
}node;
node *root=NULL;
node *create(){
    node *new;
    new=(node*)malloc(sizeof(node));
    printf("enter the number\n");
    scanf("%d",&new->info);
    new->lptr=NULL;
    new->rptr=NULL;
    return new;
}
void insert(){
    node *new,*temp=root,*prev;
    new=create();
    if(root==NULL){
        root=new;
        return;
    }
    while(temp!=NULL){
        prev=temp;
        if((temp->info)>(new->info))
            temp=temp->lptr;
        else    
            temp=temp->rptr;
    }
    if((prev->info)>new->info)
        prev->lptr=new;
    else    
        prev->rptr=new;
    return;
}
void inorder(node *temp){
    if(temp!=NULL){
        inorder(temp->lptr);
        printf("%d\t",temp->info);
        inorder(temp->rptr);
    }
}
void preorder(node *temp){
    if(temp!=NULL){
        printf("%d\t",temp->info);
        preorder(temp->lptr);
        preorder(temp->rptr);
    }
}
void postorder(node *temp){
    if(temp!=NULL){
        postorder(temp->lptr);
        postorder(temp->rptr);
        printf("%d\t",temp->info);
    }
}
int main(){
    int ch,n;
    //node *temp=root;
    while(1){
        printf("\nEnter the choice\n1.insert\n2.traversal\n3.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the number of nodes\n");
                    scanf("%d",&n);
                    for (size_t i = 0; i < n; i++)
                    {
                        insert();
                    }
                    //insert();
                    break;
            case 2: printf("\ninorder :");
                    inorder(root);
                    printf("\npreoder:");
                    preorder(root);
                    printf("\npostoder:");
                    postorder(root);
                    break;
            default: exit(0);
        }
    }
}