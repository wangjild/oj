#include <cstdio>
#include <algorithm>

using namespace std;

char str[18];

int main() {
    int c;
    scanf("%d", &c); getchar();
    while (c--) {
        int N, H;
        scanf("%d%d", &N, &H); getchar(); 
        if (c > 0)
            getchar();
        for (int i= 0; i < N - H; ++i) {
            str[i] = '0';
        }
        for (int i = N - H; i < N; ++i) {
            str[i] = '1';
        }
        str[N] = '\0';

        do {
            printf("%s\n", str);
        } while (next_permutation(str, str + N));
        
        if (c > 0) printf("\n");
    }
}
