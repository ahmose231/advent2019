#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPELEN 1000
#define WORDLEN 32
#define SQ 100

long long int run_tape(long long[], int, long long int, long long int);


void main()
{
	int c;
	char word[WORDLEN];
    long long int tape[TAPELEN];
	int k=0;		
	int tindex=0;	
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

    int count;
    
    int grid=0;
    int gridold=0;
    int tried;
    long long int temp=0;
    int newline;
    for(long long int i=5;;i++)
    {
        newline=1;
        for(long long int j=temp;;j++)
        {
            gridold=grid;
            grid=run_tape(tape, tindex, i,j);
            if(grid==0 && gridold==1)
                break;
            if(grid && newline)
            {
                newline=0;
                temp=j;
            }
            
            if(grid)
            {
                if(run_tape(tape,tindex,i+SQ-1,j))
                    if(run_tape(tape,tindex,i,j+SQ-1))
                    {
                        printf("%d\n",i*10000+j);
                        return;
                    }
            }
        }
    }
    return;
}


	
long long int run_tape(long long oldtape[], int tindex, long long int x, long long int y)
{
    long long tape[TAPELEN];
    for(int i=0;i<tindex;i++)
        tape[i]=oldtape[i];
    long long int stack[2];
    stack[0]=x;
    stack[1]=y;
    int sindex=2;
    int trailing=0;
    long long int output;
	int cursor;
	int mode[3];
	int opcode;
	long long int parameter[3];
	int n;
	int rbase; 
    int k;
    
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
				tape[parameter[0]]=stack[trailing++];
				cursor += 2;
				break;
				
			case 4:
				output = tape[parameter[0]];
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
	return output;
	
}

 
