#include<stdio.h>
#include<stdlib.h>
FILE *fp;
struct hash_table
{
    int token;
    char name[20];
}file[20];
int table[20],ct=1,pos;
void display(int n){
    fp=fopen("hash_table.txt","w");
    printf("data of hash table:\n");
    for (size_t i = 0; i < 20; i++)
    {
        printf("T[%d]->%d\n",i,table[i]);
        fprintf(fp,"Person - %d\nName: %s \tToken number: %d\n",ct++,file[i].name,file[i].token);
    }
    fclose(fp);
}
int main(){
    int n;
    printf("enter the total number of data\n");
    scanf("%d",&n);
    for(size_t i=0;i<20;i++){
        table[i]=-1;//initializing sentinal value
    }
    //here size of hash table remains constant = 20(mod 20)
    for(size_t i=0;i<n;i++){//getting the details
    printf("enter the details\n");
    scanf("%d%s",&file[i].token,file[i].name);
    }
    for(size_t i=0;i<n;i++){
        pos=(file[i].token)%20;
        if(table[pos]==-1){
        table[pos]=file[i].token;
        }
        else{
            printf("collision occured at %d position, solving collision using linear probing\n",file[i].token);
            pos=((file[i].token%20)+1)%20;
            if(table[pos]==-1)
                table[pos]=file[i].token;
        }
    }
    display(n);
}