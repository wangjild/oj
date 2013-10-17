#include <cstdio>

int main() {
    int c;
    scanf("%d", &c);

    while (c--) {

        int a, f;
        scanf("%d%d", &a, &f);
        while (f--) {
        
            for(int i = 1; i <= a; ++i) {
                for (int j = 1; j <= i; ++j)
                    printf("%d", i);
                printf("\n");
            }
            for (int i = a - 1; i >= 1; --i) {
                for (int j = 1; j <= i; ++j)
                    printf("%d", i);
                printf("\n");
            }

            if (f > 0) {
                printf("\n");
            }
        }

        if (c > 0)
            printf("\n");
    }
}
