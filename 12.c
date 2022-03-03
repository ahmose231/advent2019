#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 64
#define STEPS 1000

struct proto_moon {
	int p[3];	//position
	int v[3];	//velocity
} moon[4];

void main()
{
	char line[LEN];
	for(int i=0;i<4;i++)
	{
		fgets(line,LEN,stdin);
		sscanf(line,"<x=%d, y=%d, z=%d>",&moon[i].p[0], &moon[i].p[1], &moon[i].p[2]);
	}

	
	for(int step=0;step<STEPS;step++)
	{
		for(int m=0;m<4;m++)
		{
			for(int d=0;d<3;d++)
			{
				for(int i=0;i<4;i++)
				{
					if(m==i)
						continue;
					if(moon[m].p[d]<moon[i].p[d])
						moon[m].v[d]++;
					if(moon[m].p[d]>moon[i].p[d])
						moon[m].v[d]--;
				}

			}
		}
		
		for(int m=0;m<4;m++)
			for(int d=0;d<3;d++)
				moon[m].p[d] += moon[m].v[d];
			
	}

	int pot, kin, total=0;
	
	for(int m=0;m<4;m++)
	{
		pot=0;
		kin=0;
		for(int d=0;d<3;d++)
		{
			pot+=abs(moon[m].p[d]);
			kin+=abs(moon[m].v[d]);
		}
		
		total+=pot*kin;
	}
	
	printf("%d\n",total);
	
	return;
}
		
	
					
