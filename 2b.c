#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int m[512];
	int n[512];
	int k=0;
	char line[1024];
	fgets(line,1024,stdin);

	char *token;
	token=strtok(line,",");
	while(token!=NULL)
	{
		m[k++]=atoi(token);
		token=strtok(NULL,",");
	}

	int p;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		{
			for(int h=0;h<k;h++)
				n[h]=m[h];
			n[1]=i;
			n[2]=j;
			
			p=0;
			while(n[p]!=99)
			{
				switch(n[p])
				{
					case 1:
						n[n[p+3]]=n[n[p+1]] + n[n[p+2]];
						p=p+4;
						break;
					case 2:
						n[n[p+3]]=n[n[p+1]] * n[n[p+2]];
						p=p+4;
						break;
				}
			}
			if(n[0]==19690720)
			{
				printf("%d\n",(i*100)+j);
				return 0;
			}
		}
		
	return 0;
}
