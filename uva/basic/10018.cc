#include <cstdio>

int main() {
    int c;

    scanf("%d", &c);
    while(c--) {
        long long orig, idx = 0;
        scanf("%lld", &orig);
        while (true) {
            long long d = orig, reverse = 0;

            while (d) {
                reverse = 10 * reverse + (d % 10);
                d /= 10;
            }

            if (reverse == orig) {
                printf("%lld %lld\n", idx, reverse);
                break;
            }
            orig += reverse; ++idx;
        }
    }

    return 0;
}
