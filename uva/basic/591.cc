#include <cstdio>
#include <cstdlib>
using namespace std;
 
int main(){
  int setnum = 1;
  int n, box[55], average, count;
  while( scanf( "%d", &n ) != EOF && n ){
    average = 0;
    count = 0;
    for( int i = 0 ; i < n ; i++ ){
      scanf( "%d", &box[i] );
      average += box[i];
    }
    average /= n;
    for( int i = 0 ; i < n ; i++ )
      count += abs(average - box[i]);
    count /= 2;
    printf( "Set #%d\nThe minimum number of moves is %d.\n\n", setnum++, count );
  }
  return 0;
}
