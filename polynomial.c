#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly{
	int cf,px,py,pz,flag;
	struct poly *next;
}node;
node* getnode(){
	node *new;
	new=(node*)malloc(sizeof(node));
	new->next=new;
	return new;
}
node* insert_rear(int cf, int px, int py, int pz,node *head){
	node *new,*temp;
	new=getnode();
	new->cf=cf;
	new->px=px;
	new->py=py;
	new->pz=pz;
	new->flag=0;
	temp=head->next;
	while(temp->next!=head)
		temp=temp->next;
	temp->next=new;
	new->next=head;
	return head;
}
node* read_poly(node *head){
	node *new;int cf,px,py,pz,ch;
	do{
	printf("enter the coefficient\n");
	scanf("%d",&cf);
	printf("enter the powers of x,y,z\n");
	scanf("%d%d%d",&px,&py,&pz);
	new=insert_rear(cf,px,py,pz,head);
	printf("to continue press 1 else 0\n");
	scanf("%d",&ch);
	}while(ch!=0);
	return new;
}
void display(node *head){
	node *temp=head->next;
	while(temp!=head){
		printf("%d*x^%d*y^%d*z^%d\n",temp->cf,temp->px,temp->py,temp->pz);
		if(temp->next!=head)
			printf("+");
		temp=temp->next;
	}
	printf("\n");
}
void evaluate(node *head){
	int x,y,z,ans=0;
	node *temp=head->next;
	printf("enter the values for x,y,z\n");
	scanf("%d%d%d",&x,&y,&z);
	while(temp!=head){
		ans=ans+(temp->cf*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz));
		temp=temp->next;
	}
	printf("answer=%d",ans);
}
void main(){
	int ch;node *head;
	while(1){
		printf("enter the choice\n1.evaluate\n2.addition\n3.exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:	head=getnode();
					printf("enter the polynomial expression\n");
					head=read_poly(head);
					display(head);
					evaluate(head);
					free(head);
					break;
			default: exit(0);
		}
	}
}