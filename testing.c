#include<stdio.h>
#include<stdlib.h>
typedef struct bst {
	int info;
	struct bst *lptr,*rptr;
}node;
int min;
node *create(){
	node *new;
	new=(node*)malloc(sizeof(node));
	new->lptr=NULL;
	new->rptr=NULL;
	return new;
}
node *insert(int ele,node *root){
	node *new,*temp=root,*prev;
	new=create();
	new->info=ele;
	if(root==NULL){
		root=new;
		return root;
	}
	while(temp!=NULL){
		prev=temp;
		if(ele>temp->info)
			temp=temp->rptr;
		else 	temp=temp->lptr;
	}
	if(ele>prev->info)
		prev->rptr=new;
	else 	prev->lptr=new;
	return root;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->lptr);
		printf("%d\t",root->info);
		inorder(root->rptr);
	}
}
void preorder(node *root){
	if(root!=NULL){
		printf("%d\t",root->info);
		preorder(root->lptr);
		preorder(root->rptr);
	}
}
void postorder(node *root){
	if(root!=NULL){
		postorder(root->lptr);
		postorder(root->rptr);
		printf("%d\t",root->info);
	}
}
int findmin(node *root){
	if(root!=NULL){
		min=root->info;
		findmin(root->lptr);
	}
}
void delete(int del, node *root){
	node *prev;
	if(del>root->info){
		prev=root;
		delete(del,root->rptr);
	}
	else if(del<root->info){
		prev=root;
		delete(del,root->lptr);
	}
	else if(del==root->info){
		if(root->lptr==NULL && root->rptr==NULL){
			printf("deleted item is %d\n",root->info);
			free(root);
			return;
		}
		/*else if(root->lptr!=NULL || root->rptr!=NULL){
			printf("deleted item is %d\n",root->info);
			findmin(root->rptr);
			printf("min:%d\n",min);
			root->info=min;
		}*/
		else if(root->rptr==NULL){
			printf("deleted item is %d\n",root->info);
			if(root->info>prev->info)
				prev->rptr=root->lptr;
			else	prev->lptr=root->lptr;
			free(root);
			return;
		}
		else if(root->lptr==NULL){
			findmin(root->rptr);
			printf("min:%d\n",min);
			root->info=min;
			return;
		}
	}
}
void main(){
	int ch,ele,n,del;
	node *root=NULL;
	while (1)
	{
		printf("enter the choice\n1.insert\n2.traversal\n3.search\n4.delete\n5.exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("enter the number of elements\n");
					scanf("%d",&n);
					for(int i=0;i<n;i++){
					printf("enter the element\n");
					scanf("%d",&ele);
					root=insert(ele,root);
					}
					break;
			case 2: if(root==NULL){
						printf("tree is empty\n");
						}
					else{
						printf("\ninorder : \t");
						inorder(root);	
						printf("\npreorder : \t");
						preorder(root);
						printf("\npostorder: \t");
						postorder(root);
					}
					break;
			case 4: printf("enter the element to be deleted :\n");
					scanf("%d",&del);
					delete(del,root);
					break;
			default: exit(0);
		}
	}
	
}