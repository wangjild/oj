#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int  t,a,b,c,d;
    while ( scanf("%d",&t) != EOF ) 
        for ( int i = 1 ; i <= t ; ++ i ) {
            scanf("%d%d%d",&a,&b,&c);
            if ( b < a ) {
                d = a;a = b;b = d;
            }
            if ( c < a ) {
                d = a;a = c;c = d;
            }
            if ( c < b ) {
                d = b;b = c;c = d;
            }
            printf("Case %d: %d\n",i,b);
        }
    return 0;
}

