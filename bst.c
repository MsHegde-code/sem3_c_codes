#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int info;
    struct bst *rptr,*lptr;
}node;
node *root=NULL;
node* insert(node *root){
    node *new,*current=root,*prev;
    new=(node*)malloc(sizeof(node));
    printf("enter the number\n");
    scanf("%d",&new->info);
    new->rptr=NULL;
    new->lptr=NULL;
    if(root==NULL){
        return new;
    }
    while(current!=NULL){
        prev=current;
        if(current->info>new->info) current=current->lptr;
        else        current=current->rptr;
    }
    if(prev->info<current->info)    prev->rptr=new;
    else    prev->lptr=new;
    return root;
}
void inorder(node *root){
    //if(root!=NULL){
        inorder(root->lptr);
        printf("%d\t",root->info);
        inorder(root->rptr);
    //}
}
void preorder(node *root){
    printf("%d\t",root->info);
    preorder(root->lptr);
    preorder(root->rptr);
}
void postorder(node *root){
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d\t",root->info);
}
int main(){
    int ch,n;//node *root=NULL;
    while(1){
        printf("enter the choice\n1.insert\n2.transverse\n3.search\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the number of nodes\n");
                    scanf("%d",&n);
                    for (size_t i = 0; i < n; i++)
                    {
                        insert(root);
                    }
                    break;
            case 2: if(root==NULL){
                        printf("tree is empty\n");
                        }
                    else{
                    inorder(root);
                    preorder(root);
                    postorder(root);
                    }
                    break;
            case 3: //search();
                    break;
            default:exit(0);

        }
    }
}