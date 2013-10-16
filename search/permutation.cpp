#include <cstdio>

void print_permutation(int n, int* P, int* A, int cur) {
    int i, j;
    if (cur == n) {
        for(i = 0; i < n; ++i) printf("%d ", A[i]);
        printf("\n");
        return ;
    }
    for (i = 0; i < n; ++i) {
        if (!i || P[i] != P[i-1]) {
        int c1 = 0, c2 = 0;
        for (j = 0; j < cur; ++j) if (A[j] == P[i]) c1++;
        for (j = 0; j < n; ++j)   if (P[i] == P[j]) c2++;

        if (c1 < c2) {
            A[cur] = P[i];
            print_permutation(n, P, A, cur+1);
        }
        }
    }
}

int main() {
    int p[5] = {1,1,1,4,9};
    int a[10];
    print_permutation(5, p, a, 0);
}
