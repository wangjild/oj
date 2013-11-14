#include <cstdio>

char buf[64];

int num[20];
int numlen;

char op[20];
int oplen;

int main () {
    int n;
    scanf("%d\n", &n);

    while (n --) {
        gets(buf);
        int cur = 0, sum = 0;
        numlen = oplen = 0;
        while (buf[cur] != '\0') {
            if (buf[cur] >= '0' && buf[cur] <= '9') {
                sum = sum * 10 + buf[cur] - '0';
            } else {
                op[oplen ++] = buf[cur];
                num[numlen++] = sum;
            }
        }


    }
}
