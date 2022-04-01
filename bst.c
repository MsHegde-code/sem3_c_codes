#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int info;
    struct bst *rptr,*lptr;
}node;
node *root=NULL;int min=0;
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
void findmin_del(node *temp){
    if(temp!=NULL){
        if(temp->lptr==NULL){
            min=temp->info;
            free(temp);
            return;
            }
        else
            findmin_del(temp->lptr);
    }
}
/*void delete(node *temp,int key,node *prev){
    if(key>temp->info)
        delete(temp->rptr,key,temp);
    else if(key<temp->info)
        delete(temp->lptr,key,temp);
    else if(key==temp->info){
        if(temp->lptr==NULL&&temp->rptr==NULL){//leaf nodes
            if(prev->info>temp->info)
                prev->lptr=NULL;
            else if(prev->info<temp->info)
                prev->rptr=NULL;
            printf("the deleted number is %d",temp->info);
            free(temp);
        }
        else if(temp->rptr!=NULL){//internal nodes
            printf("the deleted number is %d",temp->info);
            findmin_del(temp->rptr);
            temp->info=min;
        }
    }
}*/
int main(){
    int ch,n,del_key;
    while(1){
        printf("\nEnter the choice\n1.insert\n2.traversal\n3.search\n4.delete\n5.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the number of nodes\n");
                    scanf("%d",&n);
                    for (size_t i = 0; i < n; i++)
                    {
                        insert();
                    }
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
            case 4: if(root==NULL)
                        printf("empty tree\n");
                    else{
                        printf("enter the number to be deleted:\n");
                        scanf("%d",&del_key);
                        delete(root,del_key,root);
                    }
                    break;
            default: exit(0);
        }
    }
}