#include <cstdio>
#include <climits>

int main() {
    int c; scanf("%d", &c);
    while (c--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b) {
            printf("<\n");
        } else if (a > b) {
            printf(">\n");
        } else {
            printf("=\n"); 
        }
    }
    //printf("%d %d\n", INT_MIN, INT_MAX);
    return 0;
}
