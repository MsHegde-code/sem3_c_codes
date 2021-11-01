#include<stdio.h>
int main(){
    int a[5][5],b[5][5],i,j,n,m;
    printf("Enter the value for m and n\n");
    scanf("%d%d",&m,&n);
    printf("enter the numbers for 1st matrix\n");
    for(i=0;i<m;i++){
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("enter the values for 2nd matrix\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }
    printf("sum of the matrix is:\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d",a[i][j]+b[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    
    return 0;
}