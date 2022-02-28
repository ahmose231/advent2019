#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPELEN 10000
#define WORDLEN 32
#define STACK 100


void main()
{
	int c;
	char word[WORDLEN];

	long long int tape[TAPELEN];
	int k=0;		//word index
	int tindex=0;	//tape index
	int flag=1;
	while(flag)
	{
		c=getchar();
		if(c==EOF || c=='\n')
			flag=0;
		
		if(!flag || c==',')
		{
			word[k]='\0';
			k=0;
			tape[tindex++]=atoll(word);
		}
		else
			word[k++]=c;
	}
	
	int cursor;
	int input[STACK];
	long long int output[STACK];
	int inputindex=0;
	int inputtrailing=0;
	int outputindex=0;
	int mode[3];
	int opcode;
	long long int parameter[3];
	int n;
	int rbase; // relative base
	int R;
	
	// initial value
	input[inputindex++]=2;

	cursor=0;
	rbase=0;
	
	while(1)
	{
		opcode=tape[cursor]%100;
		if(opcode==99) break;
		
		for(int i=0;i<3;i++)
			parameter[i] = mode[i] = 0;
		
		n=tape[cursor];
		if(n>99)
		{	
			k=0;
			n=n/100;
			while(n!=0 && k<3)
			{
				mode[k++]=n%10;
				n=n/10;
			}
		}
		
		
		for(int i=0;i<3;i++)
		{	
			switch(mode[i])
			{
				case 0:
					parameter[i]=tape[cursor+1+i];
					break;
				
				case 1:
					parameter[i]=cursor+1+i;
					break;
					
				case 2:
					parameter[i]=tape[cursor+1+i] + rbase;
					break;			
			}
		}
		
		switch(opcode)
		{
			case 1:
				tape[parameter[2]]=tape[parameter[0]] + tape[parameter[1]];
				cursor += 4;
				break;
				
			case 2:
				tape[parameter[2]]=tape[parameter[0]] * tape[parameter[1]];
				cursor += 4;
				break;
				
			case 3:
				tape[parameter[0]]=input[inputtrailing++];
				cursor += 2;
				break;
				
			case 4:
				printf("%lld ",tape[parameter[0]]);
				cursor += 2;
				break;
				
			case 5:
				if(tape[parameter[0]])
					cursor=tape[parameter[1]];
				else
					cursor += 3;
				break;
				
			case 6:
				if(!tape[parameter[0]])
					cursor=tape[parameter[1]];
				else
					cursor += 3;
				break;
				
			case 7:
				if(tape[parameter[0]]<tape[parameter[1]])
					tape[parameter[2]]=1;
				else
					tape[parameter[2]]=0;
				cursor += 4;
				break;
			
			case 8:
				if(tape[parameter[0]]==tape[parameter[1]])
					tape[parameter[2]]=1;
				else
					tape[parameter[2]]=0;		
				cursor += 4;
				break;
				
			case 9:
				rbase += tape[parameter[0]];
				cursor += 2;
				break;
				
		}
	}
	

	return;
	
}

