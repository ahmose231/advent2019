#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	fp=fopen("input6","r");
	
	struct node {
		char word[4];
		int orbiting;
	};

	struct node stack[1150];
	int k=0;
	
	char line[8];
	char bit1[4];
	char bit2[4];
	
	bit1[3]=bit2[3]='\0';
	
	int flag;
	int orbitno;
	while(fgets(line,8,fp)!=NULL)
	{
		bit1[0]=line[0];
		bit1[1]=line[1];
		bit1[2]=line[2];
		
		bit2[0]=line[4];
		bit2[1]=line[5];
		bit2[2]=line[6];
		
		flag=0;
		for(int i=0;i<k;i++)
		{
			if(!k) break;
			if(strcmp(bit1,stack[i].word)==0)
			{
				flag=1;
				orbitno=i;
				break;
			}
		}
		
		if(!flag)
		{
			strcpy(stack[k].word,bit1);
			if(k)
				stack[k].orbiting=0;
			else
				stack[k].orbiting=9999;
			orbitno=k;
			k++;
		}
		
		flag=0;
		for(int i=0;i<k;i++)
		{
			if(strcmp(bit2,stack[i].word)==0)
			{
				flag=1;
				break;
			}
		}
		
		if(!flag)
		{
			strcpy(stack[k].word,bit2);
			stack[k].orbiting=orbitno;
			k++;
		}
	}
	
	int hop;
	int total=0;
	int newtarget;
	for(int i=0;i<k;i++)
	{
		hop=0;
		newtarget=stack[i].orbiting;
		while(newtarget!=9999)
		{
			hop++;
			newtarget=stack[newtarget].orbiting;
		}
		total+=hop;
	}
	
	printf("%d\n",total);
	return 0;
		
}
