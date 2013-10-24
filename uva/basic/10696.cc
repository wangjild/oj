#include <cstdio>

int main () {
    int c;
    while (scanf("%d", &c), c) {
        if (c < 101) printf("f91(%d) = 91\n", c);
        else printf("f91(%d) = %d\n", c, c - 10);
    }
}
