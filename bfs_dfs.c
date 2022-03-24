#include<stdio.h>
#include<stdlib.h>
int visit[10],reach[10],q[10],f=0,r=-1,arr[10][10],ct=0;
void bfs(int n,int v){
    printf("%d\t",v);
    visit[v]=1;
    for (size_t i = 1; i <= n; i++)
    {
        if(visit[i]==0 && arr[v][i]==1){
            q[++r]=i;visit[i]=1;
        }
    }
    if(f<=r)
        bfs(n,q[f++]);
}
void dfs(int v,int n){
    reach[v]=1;
    for (size_t i = 1; i <= n; i++)
    {
        if(arr[v][i]==1 && !reach[i]){
            printf("%d->%d\n",v,i);ct++;
            dfs(i,n);
        }
    }
}
void main(){
    //input matrix
    int v,i,j,n,ch;
    printf("enter the size of the matrix\n");
    scanf("%d",&n);
    printf("enter the matrix\n");
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    //initializing the reference arrays
    }
    for (size_t i = 1; i <= 10; i++)
    {
        visit[i]=0;reach[i]=0;
    }
    for (size_t i = 0; i < 10; i++)
    {
        q[i]=0;
    }
    //menu
    while(1){
        printf("\nenter the choice\n1.BFS\n2.DFS\n3.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the starting vertex\n");
            scanf("%d",&v);
            printf("nodes which are reachable from %d:\n",v);
            bfs(n,v);
            break;
        case 2: 
            dfs(1,n);
            if(ct==n-1) printf("graph is connected\n");
            else    printf("graph is not connected\n");
            break;
        default:exit(0);
            break;
        }
    }
}