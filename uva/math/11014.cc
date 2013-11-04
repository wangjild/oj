#include <cstdio>
#include <cmath>

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        int n, m;
        scanf("%d%d", &n, &m);
        n -= 2; int modn = n % 3; n /= 3; n += modn ? 1 : 0;
        m -= 2; int modm = m % 3; m /= 3; m += modm ? 1 : 0;

        printf("%d\n", n * m);
    }

    return 0;
}
