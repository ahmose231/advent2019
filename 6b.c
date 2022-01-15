#include <stdio.h>
#include <string.h>

#define LINECOUNT 2000
#define LEN 16
#define WORDSIZE 4

char leftside[LINECOUNT][WORDSIZE];
char rightside[LINECOUNT][WORDSIZE];
int k;  //linecount



char *delve(char *name)
{
    for(int i=0;i<k;i++)
        if(strcmp(name,rightside[i])==0)
            return leftside[i];
    return NULL;
}



void main()
{
    char line[LEN];
    k=0;
    int len;
    char *token;
    while(fgets(line,LEN,stdin)!=NULL)
    {
        len=strlen(line);
        
        if(len<2) break;
        
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[len-1]='\0';
            
        token=strtok(line,")");
        strcpy(leftside[k],token);
        
        token=strtok(NULL,")");
        strcpy(rightside[k],token);
        
        k++;
    }
    
    int count1=0;
    int count2=0;
    char token2[WORDSIZE];
    strcpy(token,"YOU");
    strcpy(token2,"SAN");
    while(1)
    {
        strcpy(token,delve(token));
        count1++;
        count2=0;
        strcpy(token2,"SAN");     
        while(strcmp(token2,"COM")!=0)
        {
            strcpy(token2,delve(token2));
            count2++;
            if(strcmp(token,token2)==0)
            {
                printf("%d\n",count1+count2-2);
                return;
            }
        }
    }
    


    return;
    
}
