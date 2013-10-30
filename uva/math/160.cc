#include <cstdio>
#include <cstring>

#define MAXN 101
#define PRIME 25
int prime[PRIME] = {
    2,3,5,7,11,
    13,17,19,23,29,
    31,37,41,43,47,
    53,59,61,67,71,
    73,79,83,89,97
};

int contain[MAXN];

void cacFactor(int num) {
    for (int i = 0; i < PRIME && prime[i] <= num; ++i) {
        while (num % prime[i] == 0) {
            ++contain[prime[i]];
            num /= prime[i];
        }
    }
}

int main() {
    int N;

    printf("string str[101] = {\n");
    for (N = 2; N <= 100; ++N) {
        memset(contain, 0, sizeof(contain));

        for (int i = 2; i <= N; ++i) {
            cacFactor(i);
        }

        printf("\"%3d! =", N);
        int count = 1;
        for (int i = 0; i < PRIME && prime[i] <= N; ++i) {
            if ((count++) % 16 == 0) {
                printf("\\n\\\n      ");
            }
            printf("%3d", contain[prime[i]]);
        }
        printf("\\n\",\n");
    }
}
