#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char type[6][4] = {
    "BCG","BGC","CBG",
    "CGB","GBC","GCB"};

int table[6][9] = {
    0,1,1, 1,1,0, 1,0,1,
    0,1,1, 1,0,1, 1,1,0,
    1,1,0, 0,1,1, 1,0,1,  
    1,1,0, 1,0,1, 0,1,1,
    1,0,1, 0,1,1, 1,1,0,
    1,0,1, 1,1,0, 0,1,1};

int data[9];

int main()
{
    while ( scanf("%d",&data[0]) != EOF ) {
        int Min = 0,spa = 1;
        for ( int i = 1 ; i < 9 ; ++ i ) {
            scanf("%d",&data[i]);
            Min += data[i];
        }
        for ( int i = 0 ; i < 6 ; ++ i ) {
            int sum = 0;
            for ( int j = 0 ; j < 9 ; ++ j )
                sum += data[j]*table[i][j];
            if ( sum < Min ) {
                Min = sum;
                spa = i;
            }
        }
        printf("%s %d\n",type[spa],Min);
    }
    return 0;
}
