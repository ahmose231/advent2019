#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 200
#define MAXLINES 70
#define MAXNAMES 16
#define NAMESIZE 16

float unpack(int n);

struct proto_leftside {
    char name[MAXNAMES][NAMESIZE];
    int value[MAXNAMES];
    int total;
} leftside[MAXLINES];

struct proto_rightside {
    char name[NAMESIZE];
    int value;
} rightside[MAXLINES];

int k=0;

int main()
{
    char line[LEN];
    int len;
    char *firsthalf, *secondhalf;
    char *token;
    char chunk[MAXNAMES][NAMESIZE];
    int cindex;
    
    while(fgets(line,LEN,stdin)!=NULL)
    {
        len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[len-1]='\0';
        

        firsthalf=strtok(line,"=>");
        secondhalf=strtok(NULL,"=>");
        cindex=0;
        token=strtok(firsthalf,",");
        while(token!=NULL)
        {
            strcpy(chunk[cindex++], token);
            token=strtok(NULL,",");
        }
        for(int i=0;i<cindex;i++)
        {
            token=strtok(chunk[i]," ");
            leftside[k].value[i]=atoi(token);
            token=strtok(NULL," ");
            strcpy(leftside[k].name[i], token);
        }
        leftside[k].total=cindex;

        token=strtok(secondhalf," ");
        rightside[k].value=atoi(token);
        token=strtok(NULL," ");
        strcpy(rightside[k].name, token);
        
        k++;
    }
    
    for(int i=0;i<k;i++)
        if(strcmp("FUEL", rightside[i].name)==0)
            printf("%f\n",unpack(i));

    return 0;
}
            
float unpack(int n)
{
    if(strcmp(leftside[n].name[0], "ORE")==0)
        return leftside[n].value[0] / rightside[n].value;
    
    float sum=0;
    for(int i=0;i<leftside[n].total;i++)
        for(int j=0;j<k;j++)
            if(strcmp(leftside[n].name[i], rightside[j].name)==0)
                sum += unpack(j) * leftside[n].value[i];
                
    return sum / rightside[n].value;
}
