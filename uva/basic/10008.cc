#include<iostream>
#include<cstdio>
#include<cctype>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<char,int> Pair;


bool compare( Pair a, Pair b ){
    if( a.second > b.second ) return true;
    if( a.second < b.second ) return false;
    if( a.first < b.first ) return true;
    return false;
}

int main(){
    int n;
    string s;
    Pair ASCII[130];

    while( scanf( "%d", &n ) != EOF ){
        for( int i = 0 ; i < 130 ; i++ ){
            ASCII[i].first = i;
            ASCII[i].second = 0;
        }
        getchar();

        for( int i = 0 ; i < n ; i++ ){
            getline( cin, s );
            for( int j = 0 ; j < s.length() ; j++ )
                if( isalpha(s[j]) )
                    ASCII[toupper(s[j])].second++;
        }

        sort( ASCII, ASCII+130, compare );
        for( int i = 0 ; i < 130 ; i++ ){
            if( ASCII[i].second )
                printf( "%c %d\n", ASCII[i].first, ASCII[i].second );    
        }
    }
    return 0;
}
