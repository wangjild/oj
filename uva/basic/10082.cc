#include <cstdio>
#include <cstring>

char ch[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
char maps[257];

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//AVXSWDFGUHJKNBIOQEASYCQZTZ
void init() {
    for ( int i = 1 ; ch[i] ; ++ i )  
        maps[ch[i]] = ch[i-1];
    maps['\n'] = '\n'; maps[' '] = ' ';
}

int main() {
    init();

    char c;
    while ((c = getchar()) != EOF) {
        putchar(maps[c]);
    }
}
