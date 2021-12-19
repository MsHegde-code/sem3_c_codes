#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max],rear=-1,front=0;
int insert_rear(){
    if(rear==max-1){
        printf("queue is full\n");
        return -1;
    }
    printf("enter the number\n");
    scanf("%d",&queue[++rear]);
}
int delete_rear(){
    if(rear==-1||front>rear){
        printf("queue is empty\n");
        return -1;
    }
    printf("item removed is %d\n",queue[rear--]);
}
int insert_front(){
    if(front==0){
        printf("queue of front is full\n");
        return -1;
    }
    printf("enter the number\n");
    scanf("%d",&queue[--front]);
}
int delete_front(){
    if(rear==-1){
        printf("queue is empty\n");
        return -1;
    }
    printf("deleted item is %d\n",queue[front++]);
}
int display(){
    if(rear==-1&&front==0){
        printf("queue is empty\n");
        return -1;
    }
    printf("entered elements are:\n");
    for (size_t i = front; i <= rear; i++)
    {
        printf("%d\t",queue[i]);
    }
    printf("\n");
}
int main(){
    int choice;
    while(1){
        printf("enter the choice\n1.insert rear\n2.insert front\n3.delete rear\n4.delete front\n5.display\n6.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:     insert_rear();
                        break;
            case 2:     insert_front();
                        break;
            case 3:     delete_rear();
                        break;
            case 4:     delete_front();
                        break;
            case 5:     display();
                        break;
            default:    exit(0);
                        break;
        }
    }
}