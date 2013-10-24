#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int max(int a, int b) { return a > b ? a : b; }

int res[150];
char str[150];

int main() {
    memset(res, 0, sizeof(int) * 150);
    int num = 0;
    while (scanf("%s", str), str[0] != '0') {
        int len = strlen(str);
        num = max(len, num);
        
        int carry = 0, idx = 0;
        for (int i = len - 1; i >= 0; --i) {
            res[idx] += str[i] - '0' + carry;
            if (res[idx] > 9) {
                carry = 1;
                res[idx] %= 10;
            } else {
                carry = 0;
            }
            ++idx;
        }
        while (idx <= num && carry) {
            res[idx] += carry;
            if (res[idx] > 9) {
                carry = 1;
                res[idx] %= 10;
            } else {
                carry = 0;
            }
            if (idx == num) num++;
            idx ++;
        }
    }

    for (int i = num - 1; i >= 0; --i)
        printf("%d", res[i]);
    printf("\n");

    return 0;
}
