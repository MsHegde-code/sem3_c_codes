#include<stdio.h>
#include<stdlib.h>
int *arr,i,n;
//functions
int create(n){
    printf("enter the array size\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("insufficient space\n");
        exit(0);
    }
    printf("enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
int show(){
    printf("the entered elements are:\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int insert1(ele,pos){
    int j=n-1;
    n++;
    arr=(int*)realloc(arr,n*sizeof(int));
    while(j>=pos){
        arr[j+1]=arr[j];
        j--;
    }
    arr[pos]=ele;
}
int delete1(pos){
    int j;
    for(j=0;j<n-1;j++){
        arr[j]=arr[j+1];
    }
    n--;
    if(n==0)    printf("no element to be deleted\n");
}
int main(){
    int i,j,n,*arr,pos,ele,selection;
    while(1){
        printf("enter the selection\n1.create an array\n2.display the array\n3.insert an element\n4.delete an element\n5.exit the program\n");
        scanf("%d",&selection);
        switch(selection){
            case 1: printf("enter the array size\n");
                    scanf("%d",&n);
                    create(n);
                    break;
            case 2: show();
                    break;
            case 3: printf("enter the element\n");
                    scanf("%d",&ele);
                    printf("enter the position\n");
                    scanf("%d",&pos);
                    insert1(ele,pos);
                    break;
            case 4: printf("enter the position\n");
                    scanf("%d",&pos);
                    delete1(pos);
                    break;
            case 5: printf("exiting\n");
                    break;
        }
    }
    free(arr);
    return 0;
}