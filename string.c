#include<stdio.h>
#include<string.h>
int i=0,j=0,k=0,m=0,c=0,flag=0;
char pat[20],str[20],rep[20],ans[20];
/*index of answer string is j
index of main string is c(for iterating words), and for iterating for letters is m
index for replace string is k
index for pattern string is i*/
void read(){
    printf("enter the main string\n");
    gets(str);
    printf("enter the pattern string\n");
    gets(pat);
    printf("enter the replace string\n");
    gets(rep);
}
void match_pat(){
    while (str[c]!='\0')
    {
        if(str[m]==pat[i]){
            i++;m++;
            if(pat[i]=='\0'){
                printf("pat:%s is found at %d position\n",pat,c);
                for(k=0;rep[k]!='\0';k++,j++){
                    ans[j]=rep[k];
                    flag=1;
                }
                i=0;c=m;
            }
        }
        else{
            ans[j]=str[c];
            j++;k++;
            m=c;i=0;

        }
    }
    if(flag==0){
        printf("pat:%s is not found in str: %s",pat,str);
    }
    else{
        ans[j++]='\0';
        printf("the resulting string is %s",ans);
    }
    
    
}
void main(){
    read();
    match_pat();
}