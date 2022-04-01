#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly{
	int cf,x,y,z,flag;
	struct poly *next;
}node;
node *create(){
	node *new;
	new=(node*)malloc(sizeof(node));
	new->next=NULL;
	return new;
}
void insert(int cf, int x, int y, int z, node *head){
	node *new,*temp=head;
	new=create();
	new->cf=cf;		new->x=x;	new->y=y; 	new->z=z; new->flag=0;
	if(head->next==NULL){
		head->next=new;
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	return;
}
void getinfo(node *head){
	int cf,x,y,z,ch;
	do{
		printf("enter the coefficient:\n");
		scanf("%d",&cf);
		printf("enter the powers x,y,z:\n");
		scanf("%d%d%d",&x,&y,&z);
		insert(cf,x,y,z,head);
		printf("to continue press 1 else 0\n");
		scanf("%d",&ch);
	}while(ch!=0);
}
node *add(node *h1, node *h2, node *h3){
	node *p1,*p2;
	//printf("check 1\n");
	p1=h1->next;
	while(p1!=NULL){
		p2=h2->next;
			while(p2!=NULL){
				if(p1->x==p2->x && p1->y==p2->y && p1->z==p2->z){
					insert(p1->cf+p2->cf,p1->x,p1->y,p1->z,h3);
					p1->flag=1;p2->flag=1;
				}
				p2=p2->next;
			}
		p1=p1->next;
	}
	//to add the left over terms of both the poly
	p1=h1->next;
	while(p1!=NULL){
		if(p1->flag==0){
			insert(p1->cf,p1->x,p1->y,p1->z,h3);
			p1->flag=1;
		}
		p1=p1->next;
	}
	p2=h2->next;
	while(p2!=NULL){
		if(p2->flag==0){
			insert(p2->cf,p2->x,p2->y,p2->z,h3);
			p2->flag=1;
		}
		p2=p2->next;
	}
	return h3;
}
void display(node *head){
        node *temp=head->next;
        if(temp==NULL){
                printf("\nlist is empty\n");
                return;
        }
        while(temp!=NULL){
                printf("%d*x^%d*y^%d*z^%d",temp->cf,temp->x,temp->y,temp->z);
                if(temp->next!=NULL)
                        printf("+\n");
                temp=temp->next;
        }
}
void evaluate(){

}
void main(){
	node *h1,*h2,*h3;int ch;
	while(1){
		printf("\nenter the choice\n1.evaluate\n2.addition\n3.exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
		case 1:
			evaluate();
			break;
		case 2:
			h1=create();
			h2=create();
			h3=create();
			printf("enter the first polynomial\n");
			getinfo(h1);
			printf("polynomial 1:\n");
			display(h1);
			printf("\nenter the second polynomial\n");
			getinfo(h2);
			printf("polynomial 2:\n");
			display(h2);
			h3=add(h1,h2,h3);
			printf("the sum is :\n");
			display(h3);
			break;
		default: exit(0);
			break;
		}
	}
}