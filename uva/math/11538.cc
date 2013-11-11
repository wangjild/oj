#include <cstdio>


int main() {
    unsigned long long m, n;
    while(scanf("%lld%lld", &n, &m), m || n) {
        if (n > m) {
            unsigned long long tmp = m;
            m = n; n = tmp;
        }

        printf("%lld\n", n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3);
    }
    return 0;
}
