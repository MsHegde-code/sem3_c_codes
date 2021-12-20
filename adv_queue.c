#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max],rear=-1,front=0,ct;
int insert(){
    if(front>rear){
        front=0;rear=-1;
    }
    if(ct==max){
        printf("queue is full\n");
        return -1;
    }
    printf("enter the number\n");
    scanf("%d",&q[++rear]);
    ct++;
}
int delete(){
    if(front>rear){
        rear=-1;front=0;
    }
    if(ct==0){
        printf("Queue is empty\n");
        return -1;
    }
    printf("the deleted number is : %d\n",q[front++]);
    ct--;
}
int display(){
    if(ct==0){
        printf("queue is empty\n");
        return -1;
    }
    printf("the elements are:\t");
    for(size_t i=front;i<=rear;i++)
        printf("%d\t",q[i]);
    printf("\n");
}
int main(){
    int ch;
    while(1){
        printf("enter the choice\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:     insert();
                        break;
            case 2:     delete();
                        break;
            case 3:     display();
                        break;
            default:    exit(0);
                        break;
        }
    }
}