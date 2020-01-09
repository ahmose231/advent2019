#include <stdio.h>
#include <stdlib.h>

int ifdoubledigits(int a)
{
	int m[10];
	int i;
	for(i=0;i<10;i++)
		m[i]=0;
	for(i=0;i<6;i++,a=a/10)
		m[a%10]++;
	for(i=0;i<10;i++)
		if(m[i]>1)
			return 1;
	return 0;
}

int ifincreasing(int a)
{
	int t1,t2;
	t1=9;
	for(int i=0;i<6;i++)
	{
		t2=a%10;
		if(t2>t1)
			return 0;
		t1=t2;
		a=a/10;
	}
	return 1;
}
		
int main(int arcg, char *argv[])
{
	char s[16];
	int i;
	for(i=0;i<6;i++)
		s[i]=argv[1][i];
	s[6]='\0';
	int a,b;
	a=atoi(s);
	for(i=0;i<6;i++)
		s[i]=argv[1][i+7];
	b=atoi(s);
	int count=0;
	for(i=a;i<=b;i++)
	{
		if(i<100000)
			continue;
		if(i>999999)
			break;
		if(ifincreasing(i) && ifdoubledigits(i))
			count++;
	}
	
	printf("%d\n",count);
	return 0;
}
