#include <cstdio>

void print_subnet(int n, int *A, int cur) {
    for (int i = 0; i < cur; ++i) printf("%d ", A[i]);
    printf("\n");

    int s = cur ? A[cur-1] + 1 : 0;
    for (int i = s; i < n; ++i) {
        A[cur] = i;
        print_subnet(n, A, cur+1);
    }
}

int main() {
    int a[5] ;

    print_subnet(5, a, 0);
}
