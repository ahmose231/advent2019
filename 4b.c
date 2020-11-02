#include <stdio.h>

int check_increase(int x)
{
	int a;
	for(int i=0;i<6;i++)
	{
		a=x%10;
		x=x/10;
		if(a<x%10)
			return 0;
	}
	return 1;
}

int check_double(int x)
{
	int m[10];
	for(int i=0;i<10;i++)
		m[i]=0;
	
	for(int i=0;i<6;i++)
	{
		m[x%10]++;
		x=x/10;
	}
	
	for(int i=0;i<10;i++)
		if(m[i]==2)
			return 1;
		
	return 0;
}

int main()
{
	int begin=172851;
	int end=675869;
	
	int count=0;
	for(int i=begin;i<end;i++)
		if(check_increase(i))
			if(check_double(i))
				count++;
	
	printf("%d\n",count);
	return 0;
}
				
