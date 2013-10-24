#include <cstdio>

int sum[102];

int init() {
    sum[0] = 0; sum[1] = 1;
    for (int i = 3; i < 102; i += 2) {
        sum[i] = sum[i-2] + i;
    }
}

int main() {
    init();
    int c; scanf("%d", &c);

    for (int i = 0; i < c; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a += (a & 0x1) ? 0 : 1;
        b -= (b & 0x1) ? 0 : 1;
        printf("Case %d: %d\n", i + 1, sum[b] - sum[a] + a);
    }

    return 0;
}
