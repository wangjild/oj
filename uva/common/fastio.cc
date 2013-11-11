#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>

const int MAXN = 10000001;
int num[MAXN];

const int MAXS = 12 * MAXN + 1;
char buf[MAXS];

void analyse(char* buf, int len = MAXS) {
    int i;
    num[i = 0] = 0;
}

int main() {
    int num;

    freopen("input.txt", "rb", stdin);
    int len = fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';

    clock_t start, finish;
    double  duration;
    start = clock();

    finish = clock();
    printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}
