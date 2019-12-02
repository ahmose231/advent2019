#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum=0;
	int k;
	char token[32];
	int tsum;
	while(fgets(token,32,stdin)!=NULL)
	{
		tsum=0;
		k=atoi(token);
		while(k>8)
		{
			k=k/3;
			k=k-2;
			tsum=tsum+k;
		}
		sum=sum+tsum;
	}
	printf("%d\n",sum);
	return 0;
}
