#include <cstdio>
#include <cstring>

#define N 102

char ch[N][N];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int stes = 0;

    memset(ch, 0, sizeof(char) * N * N);
    int maxlen = 0;
    int idx = 0;
    while (gets(ch[stes]) != NULL) {
        int len = strlen(ch[stes]);
        if (len > maxlen) {
            maxlen = len;
            idx = stes;
        }
        stes ++;
    }

    for (int j = 0; j < maxlen; ++j) {
        for (int i = stes - 1; i >= 0; --i) {
            if (ch[i][j] == '\0') {
                printf(" ");
            } else {
                printf("%c", ch[i][j]);
            }
        }
        printf("\n");
    }

}
