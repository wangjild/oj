#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
  int K, N, M, search_N, search_M;
  while( scanf( "%d", &K ) != EOF && K ){
    scanf( "%d%d", &N, &M );
    for( int i = 0 ; i < K ; i++ ){
      scanf( "%d%d", &search_N, &search_M );
      if( N == search_N || M == search_M ) printf( "divisa\n" );
      else{
        if( M > search_M ) printf( "S" );
        else printf( "N" );
        if( N > search_N ) printf( "O" );
        else printf( "E" );
        printf( "\n" );
      }
    }
  }
  return 0;
}
