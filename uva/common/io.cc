#include <cstdio>
#include <ctime>

int main() {
    int num;
    clock_t start, finish;
    start = clock();
    while (scanf("%d", &num) != EOF) {
        printf("%d\n", num);
    }
    finish = clock();

    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
