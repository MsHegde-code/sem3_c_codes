#include<stdio.h>
#include<stdlib.h>
FILE *fp;
struct hash_table
{
    int token;
    char name[20];
}file[20];
int *table,ct=1,pos,m;
void display(){
    printf("data of hash table:\n");
    for (size_t i = 0; i < m; i++)
    {
        printf("T[%d]->%d\n",i,table[i]);
    }
}
void main(){
    int n,count=0;
    printf("enter the total number of data\n");
    scanf("%d",&n);
    printf("enter the hash table size\n");
    scanf("%d",&m);
    table=(int*)malloc(m*sizeof(int));
    for (size_t i = 0; i < m; i++)
    {
        table[i]=-1;
    }
    fp=fopen("hash_table.txt","w");
    for(size_t i=0;i<n;i++){//getting the details
    printf("enter the details\n");
    scanf("%d%s",&file[i].token,file[i].name);
    fprintf(fp,"Person - %d\nName: %s \tToken number: %d\n",ct++,file[i].name,file[i].token);
    }
    for(int i=0;i<n;i++){
        if(count==m){
            printf("hash table is full,cannot insert the file %d\n",file[i].token);
        }
        else{
        pos=file[i].token % m;
        while(table[pos]!=-1){
            printf("collision occured at %d key,resolving using linear probing\n",file[i].token);
            pos=(pos+1 )% m;
            }
        table[pos]=file[i].token;
        count++;
        }
    }
    fclose(fp);
    display();
}