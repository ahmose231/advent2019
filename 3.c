#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

char newline1[301][5]; 
char newline2[301][5]; 

int rundownline2( int x1,  int y1 )
{
	int x2, y2; 
	x2 = y2 = 0; 
	int count; 
	char num[5]; 

	
	for( int m = 0; m < 301; m++ )
	{
		strcpy( num, newline2[m] ); 
		num[0] = '0'; 
		count = atoi( num ); 

		for( int i = 0; i < count; i++ )
		{
			switch( newline2[m][0] )
			{
				case 'U':
				y2++; 
				break; 
				
				case 'D':
				y2--; 
				break; 
				
				case 'R':
				x2++; 
				break; 
				
				case 'L':
				x2--; 
				break; 
			}
			

			if( ( x1 == x2 ) && ( y1 == y2 ) )
				return 1; 
		}
	}
	
	return 0; 
}
			

int main(  )
{
	char line1[1500]; 
	char line2[1500]; 
	
	FILE *fp; 
	fp = fopen( "input3","r" ); 
	
	fgets( line1, 1500, fp ); 
	fgets( line2, 1500, fp ); 
	
	line1[strlen( line1 ) - 1] = '\0'; 
	line2[strlen( line2 ) - 1] = '\0'; 
	
	fclose( fp ); 

	char *token; 
	int k = 0; 
	token = strtok( line1, "," ); 
	while( token!= NULL )
	{
		strcpy( newline1[k], token ); 
		k++; 
		token = strtok( NULL, "," ); 
	}
	
	k = 0; 
	token = strtok( line2, "," ); 
	while( token != NULL )
	{
		strcpy( newline2[k], token ); 
		k++; 
		token = strtok( NULL, "," ); 
	}
	
	int x1, y1; 
	x1 = y1 = 0; 
	
	int manhattan; 
	int min = 0; 
	int init=0;
	int count; 
	char num[5]; 

	for( int m = 0;  m < k;  m++ )
	{
		
		strcpy( num, newline1[m] ); 
		num[0] = '0'; 
		count = atoi( num ); 

		for( int i = 0;  i < count;  i++ )
		{
			switch( newline1[m][0] )
			{
				case 'U':
				y1++; 
				break; 
				
				case 'D':
				y1--; 
				break; 
				
				case 'R':
				x1++; 
				break; 
				
				case 'L':
				x1--; 
				break; 
			}
			
		
		
			if( rundownline2( x1,  y1 ) )
			{
				manhattan = ( abs( x1 ) + abs( y1 ) ); 
				
				if( !init )
				{
					min = manhattan; 
					init = 1;
				}
				else
					if( manhattan < min )
						min = manhattan; 
			}
		}
	}
	
	
	printf( "%d\n", min ); 
}
			
