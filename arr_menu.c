#include<stdio.h>
#include<stdlib.h>
int i,j,pos,ele,*data,n,selection;
//functions
void create(int n){
    data=(int*)malloc(n*sizeof(int));
    printf("enter the array elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",(data+i));
    }
    printf("\n");
    
}
void display(int n){
    printf("the entered elements are:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",*(data+i));
    }
    printf("\n");
    
}
void insert(int ele,int pos,int n){

    data=(int*)realloc(data,n*sizeof(int));
    while(j>=pos){
        data[j+1]=data[j];
        j--;
    }
    data[j]=ele;
}
void delete(int pos, int n){
    for(j=pos;j<n-1;j++){
        data[j]=data[j+1];
    }
    if(n==0)    printf("no elements to be deleted\n");
}

int main(){
    while(1){
        label1:printf("enter the selection:\n1.create an array\n2.display the array\n3.insert an element\n4.delete a position\n5.exit\n");
        scanf("%d",&selection);
        switch(selection){
            case 1: printf("enter the array size:\n");
                    scanf("%d",&n);
                    create(n);
                    break;
            case 2: display(n);
                    break;
            case 3: printf("enter the element\n");
                    scanf("%d",&ele);
                    printf("enter the position\n");
                    scanf("%d",pos);
                    n=j-1;
                    n++;
                    insert(ele,pos,n);
                    break;
            case 4: printf("enter the position\n");
                    scanf("%d",&pos);
                    delete(ele,n);
                    n--;
                    break;
            case 5: printf("exiting...\n");
                    free(data);
                    exit(0);
                    break;
            default:printf("enter a valid selection\n");
                    goto label1;
        }
    }
    return 0;
}