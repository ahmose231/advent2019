#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPELEN 10000
#define WORDLEN 32
#define STACK 100

#define N    5   // number of elements to permute.  Let N > 2
int phases[120][5];
int total=0;

void display(unsigned int *a, unsigned int j, unsigned int i)            
{
   for(unsigned int x = 0; x < N; x++)
      phases[total][x]=a[x]-1;
   total++;
} // display()

// NOTICE:  quickperm.c Copyright 1991-2010, Phillip Paul Fuchs
void quickperm(void)
{
   unsigned int a[N], p[N+1];
   register unsigned int i, j, tmp; // Upper Index i; Lower Index j

   for(i = 0; i < N; i++)   // initialize arrays; a[N] can be any type
   {
      a[i] = i + 1;   // a[i] value is not revealed and can be arbitrary
      p[i] = i;
   }
   p[N] = N; // p[N] > 0 controls iteration and the index boundary for i
   display(a, 0, 0);   // remove comment to display array a[]
   i = 1;   // setup first swap points to be 1 and 0 respectively (i & j)
   while(i < N)
   {
      p[i]--;             // decrease index "weight" for i by one
      j = i % 2 * p[i];   // IF i is odd then j = p[i] otherwise j = 0
      tmp = a[j];         // swap(a[j], a[i])
      a[j] = a[i];
      a[i] = tmp;
      display(a, j, i); // remove comment to display target array a[]
      i = 1;              // reset index i to 1 (assumed)
      while (!p[i])       // while (p[i] == 0)
      {
         p[i] = i;        // reset p[i] zero value
         i++;             // set new index value for i (increase by one)
      } // while(!p[i])
   } // while(i < N)
} // QuickPerm()



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
    int amp_output;
    int max=0;
    
    quickperm();
    
    for(int perm=0;perm<120;perm++)
    {
        amp_output=0;
        for(int amp=0;amp<5;amp++)
        {
        	inputindex=0;
        	inputtrailing=0;
            input[inputindex++]=phases[perm][amp];
            input[inputindex++]=amp_output;
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
        				amp_output=tape[parameter[0]];
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
        }
        
        if(max<amp_output)
            max=amp_output;
            
    }
    
    printf("%d\n",max);
	return;
	
}

