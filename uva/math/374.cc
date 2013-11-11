#include <cstdio>

int solve(int B, int P, int M) {
    if (P == 0) return 1;
    if (P == 1) return B % M;

    int div = P/2;
    int remain = solve(B, div, M);
    remain = (remain * remain) % M;
    if (P % 2 != 0) {
        remain = (remain * B) % M;
    }
    return remain;
}

int main () {
    int B, P, M;
    while (scanf("%d\n%d\n%d", &B, &P, &M) != EOF) {
        printf("%d\n", solve(B, P, M));
    }
}
