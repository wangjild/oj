#include <cstdio>

int s = 1960;

int main() {
    
    int year;

    while (scanf("%d", &year), year) {
        int num = 1 << ((year - s) / 10 + 2);
        int mul = 1, ans = 0;
        for (int i = 1; i < 1024; ++i) {
            mul *= i;
            if (mul > num) {
                ans = i - 1;
                break;
            }
        }

        printf("%d\n", ans);
    }
}
