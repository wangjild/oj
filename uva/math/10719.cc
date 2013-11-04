#include <cstdio>

int p[1005];

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        int len = 0;
        while(1) {
            char c;
            scanf("%d%c", &p[len++], &c);
            printf("%d%c", p[len - 1], c);
            if (c == '\n') break;
        }

        printf("q(x) :");
        int i = 0, q = p[0];
        do {
            printf(" %d", q);
            ++i;
            q = p[i] + k*q;
        } while (i < len - 1);
        printf("\nr : %d\n\n", q);
    }
    return 0;
}
