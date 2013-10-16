#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int C, N, S;
int sum[MAX_N + 1];
int a[MAX_N + 1];

int main() {
    scanf("%d", &C);

    while (C--) {
        scanf("%d%d", &N, &S);
        scanf("%d", &a[0]);
        for(int i = 1; i < N; ++i) {
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }

        if (sum[N-1] < S) {
            printf("0\n");
            continue;
        }

        int res = N - 1;
        for(int s = 0; S <= sum[N-1] - sum[s]; ++s) {
            int t = lower_bound(sum + s, sum + N, sum[s] + S) - sum;
            res = min(res, t-s);
        }

        printf("%d\n", res);
    }

    return 0;
}
