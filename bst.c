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
void search(node *temp){
    int key,flag=0;
    //node *temp=root;
    printf("enter the key to search\n");
    scanf("%d",&key);
    while(temp!=NULL){
        if(key==temp->info){
            flag=1;break;
        }
        else if(key>temp->info)
            temp=temp->rptr;
        else if(key<(temp->info))
            temp=temp->lptr;
        }
    if(flag==1) printf("%d is present in the tree\n",key);
    else printf("%d is not present in the tree\n",key);
}
int main(){
    int ch,n;
    while(1){
        printf("\nEnter the choice\n1.insert\n2.traversal\n3.search\n4.exit\n");
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
            case 2: if(root==NULL){
                        printf("empty tree\n");
                        }
                    else{
                    printf("\ninorder :");
                    inorder(root);
                    printf("\npreoder:");
                    preorder(root);
                    printf("\npostoder:");
                    postorder(root);
                    }
                    break;
            case 3: if(root==NULL)
                        printf("empty tree\n");
                    else
                        search(root);
                    break;
            default: exit(0);
        }
    }
}