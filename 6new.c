#include <stdio.h>
#include <string.h>

#define LINECOUNT 2000
#define LEN 16
#define WORDSIZE 4

char leftside[LINECOUNT][WORDSIZE];
char rightside[LINECOUNT][WORDSIZE];
int k;  //linecount

int delve(char *name)
{
    if(strcmp(name,"COM")==0)
        return 0;
    for(int i=0;i<k;i++)
    {
        if(strcmp(name,rightside[i])==0)
        {
            return 1+delve(leftside[i]);
        }
    }
    return 0;
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

    
    int total=0;
    for(int i=0;i<k;i++)
        total += delve(rightside[i]);
        
        
    printf("%d\n",total);
        



    return;
    
}
