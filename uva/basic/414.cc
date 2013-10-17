#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 13
int sqr[13][2];
char ch[26];

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int c;
    while (scanf("%d", &c), getchar(), c != 0) {
        int m = 2^31 - 1;
        int sum = 0;
        for(int i = 0; i < c; ++i) {
            gets(ch);

            int len = strlen(ch);
            int count = 0;
            int first = 0;
            for (int j = 0; j < len; ++j) {
                if (ch[j] == ' ' || ch[j] == 'B') {
                    first = (first == 0) ? j : first;
                    count ++;
                    sum ++;
                }
            }

            sqr[i][0] = first;
            sqr[i][1] = count;
            m = min(count, m);
        }

        printf("%d\n", sum - m * c);
    }
}
