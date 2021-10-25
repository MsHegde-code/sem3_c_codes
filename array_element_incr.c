#include<stdio.h>
int main(){
	int i,arr[5];
	printf("enter the array elements\n");
	for(i=0;i<5;i++){
	scanf("%d",&arr[i]);
	}
	for(i=0;i<5;i++){
		arr[i]++;
		printf("%d \t",arr[i]);
	}
	return 0;
}