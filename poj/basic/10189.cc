#include <cstdio>
#include <cstdlib>
#include <cstring>

char maps[ 103 ][ 103 ];
int  numb[ 103 ][ 103 ];
int  dxdy[ 8 ][ 2 ] = {1,0,0,1,-1,0,0,-1,1,-1,-1,1,1,1,-1,-1};

int main()
{
    int n,m,c = 1; 
    while ( scanf("%d%d",&n,&m) && m+n ) {
        for ( int i = 0 ; i < n ; ++ i )
            scanf("%s",maps[ i ]);

        memset( numb, 0, sizeof( numb ) );
        for ( int i = 0 ; i < n ; ++ i )
            for ( int j = 0 ; j < m ; ++ j )
                if ( maps[ i ][ j ] == '*' ) 
                    for ( int k = 0 ; k < 8 ; ++ k ) {
                        int x = i + dxdy[ k ][ 0 ];
                        int y = j + dxdy[ k ][ 1 ];
                        if ( x >= 0 && x < n && y >= 0 && y < m )
                            ++ numb[ x ][ y ];
                    }

        if ( c > 1 ) printf("\n");
        printf("Field #%d:\n",c ++);
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j < m ; ++ j )
                if ( maps[ i ][ j ] == '*' )
                    printf("*");
                else printf("%d",numb[ i ][ j ]);
            printf("\n");
        }
    }
    return 0;
}
