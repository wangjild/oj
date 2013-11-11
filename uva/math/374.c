#include <stdio.h>

long long solve(long long B, long long P, long long M) {
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
    long long B, P, M;
    while (scanf("%lld\n%lld\n%lld", &B, &P, &M) != EOF) {
        printf("%lld\n", solve(B, P, M));
    }
}
