  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int m[700];
	int k=0;
	char line[10240];
	fgets(line,10240,stdin);
	
	
	char *token;
	token=strtok(line,",");
	while(token!=NULL)
	{
		m[k++]=atoi(token);
		token=strtok(NULL,",");
		
	}
	
	
	int p=0;
	int instruction;
	int mode1,mode2,mode3;
	int input=1;
	int output;
	int parameter1,parameter2;
	while(m[p]!=99)
	{
		if (m[p]<10)
		{
			instruction=m[p];
			mode1=mode2=mode3=0;
		}
		else
		{
			instruction=m[p]%10;
			mode1=(m[p]/100)%10;
			mode2=(m[p]/1000)%10;
			mode3=(m[p]/10000)%10;
		}
		switch(instruction)
		{
			case 1:
				if(!mode1)
					parameter1=m[m[p+1]];
				else
					parameter1=m[p+1];
				
				if(!mode2)
					parameter2=m[m[p+2]];
				else
					parameter2=m[p+2];
				
				m[m[p+3]]=parameter1+parameter2;
				p=p+4;
				break;
			case 2:
				if(!mode1)
					parameter1=m[m[p+1]];
				else
					parameter1=m[p+1];
				
				if(!mode2)
					parameter2=m[m[p+2]];
				else
					parameter2=m[p+2];
				
				m[m[p+3]]=parameter1*parameter2;
				p=p+4;
				break;
			case 3:
				m[m[p+1]]=input;
				p=p+2;
				break;
			case 4:
				if(!mode1)
					parameter1=m[m[p+1]];
				else
					parameter1=m[p+1];
				output=parameter1;
				p=p+2;
				break;
				
		}
	}
	printf("%d\n",output);
	return 0;
}
