#include <cstdio>
#include <ctime>

int main() {
    int num;
	freopen("input.txt", "rb", stdin);
    clock_t start, finish;
    start = clock();
    while (scanf("%d", &num) != EOF) ;
    finish = clock();

	printf("%d\n", num);
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
