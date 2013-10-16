#include <cstdio>
#include <cstdlib>

int main() {

    long long a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        printf("%lld\n", abs(b - a));
    }
    return 0;
}
