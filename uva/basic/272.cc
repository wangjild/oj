#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000]; 

int main()
{
    int n = 0; 
    while ( gets(str) ) {
        for ( int i = 0 ; str[i] ; ++ i )
            if ( str[i] == '"' ) {
                if ( ++ n % 2 ) printf("``");
                else printf("''");
            }else printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}

