#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int m[512];
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

	m[1]=12;
	m[2]=2;
	
	int p=0;
	
	while(m[p]!=99)
	{
		switch(m[p])
		{
			case 1:
				m[m[p+3]]=m[m[p+1]] + m[m[p+2]];
				p=p+4;
				break;
			case 2:
				m[m[p+3]]=m[m[p+1]] * m[m[p+2]];
				p=p+4;
				break;
		}
	}
	printf("%d\n",m[0]);
	return 0;
}
