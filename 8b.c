#include <stdio.h>

int main()
{
    char grid[6][25];
    
    for(int i=0;i<6;i++)
        for(int j=0;j<25;j++)
            grid[i][j]='2';
            
    char c;

    while(1)
        for(int i=0;i<6;i++)
            for(int j=0;j<25;j++)
            {      
                c=getchar();
                
                if(c=='\n' || c==EOF) goto next;
                
                if(grid[i][j]=='2')
                    grid[i][j]=c;
                
                
            }
    next:
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<25;j++)
            printf("%c",grid[i][j]=='1'?'#':' ');
        printf("\n");
    }
    
    return 0;
}
