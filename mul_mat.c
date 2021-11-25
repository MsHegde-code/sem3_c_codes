#include<stdio.h>
int i,j,k,mat1[5][5],mat2[5][5],c[5][5],n;
int main(){
  printf("enter the matrix size\n");
  scanf("%d",&n);
  printf("enter the 1st matrix elements \n" );
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
    scanf("%d",&mat1[i][j]);
  }
  printf("enter the 2nd matrix elements\n" );
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      scanf("%d\n",&mat2[i][j] );
    }
  }
  printf("the product of matrices are: \n");
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      for ( k = 0; k < n; k++) {
        printf("%d\n",c[i][j]=c[i][j]+(mat1[i][k]*mat2[k][j]) );
      }
    }
  }
  return 0;
}
