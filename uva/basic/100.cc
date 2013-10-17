#include <cstdio>
#include <cstdlib>

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int aa, bb;
    while (scanf("%d%d", &aa, &bb) != EOF) {

        int a = min(aa, bb);
        int b = max(aa, bb);

        int maxlen = 0;
        for (int i = a; i <= b; ++i) {
            // solve
            int n = i;
            int len = 1;
            while (n != 1) {
                ++ len;
                if (n % 2 == 1) {
                    n = 3*n + 1;
                } else {
                    n /= 2;
                }
            }

            maxlen = max(len, maxlen);
        }

        printf("%d %d %d\n", aa, bb, maxlen);
    }
}
