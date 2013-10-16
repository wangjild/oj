#include <cstdio>
#include <cstring>

#define MAX_N 24
int sqr[MAX_N][MAX_N];

int set[MAX_N];

inline int max(int a, int b) {
    return a > b ? a : b;
}

const int A = 0; // set A
const int B = 1; // set B

int max_val = 0;
int num;

void dfs(int k, int sum) {
    if (k == num) {
        max_val = max(sum, max_val);
        return ;
    }

    int diff = 0;
    for(int i = 0; i < num; ++i) {
        if (set[i] == B)
        {
            diff -= sqr[i][k];
        } else {
            diff += sqr[i][k];
        }
    }

    if (diff > 0) {
        set[k] = B;
        dfs (k+1, sum + diff);
    }
    set[k] = A;
    dfs(k+1, sum);
}

int main() {

    while (scanf("%d", &num) != EOF) {

        max_val = 0;
        memset(set, 0, sizeof(int) * MAX_N);
        for(int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                scanf("%d", &sqr[i][j]);
            }
        }

        dfs(0, 0);

        printf("%d\n", max_val);
    }

    return 0;
}
