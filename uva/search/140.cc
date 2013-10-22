#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[256];
#define MAXN 26
int sqr[MAXN][MAXN];
char ch[MAXN];
char record[MAXN];

int num;

void processStr() {
    int len = strlen(str);
    str[len++] = ';';
    str[len] = '\0';

    for(int i = 0; i < len; ++i) {
        int head = str[i] - 'A';
        record[head] = 1;
        i += 2;
        while (str[i] != ';') {
            int tail = str[i++] - 'A';
            record[tail] = 1;
            sqr[head][tail] = sqr[tail][head] = 1;
        }
    }
}

void print() {
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%d ", sqr[i][j]);
        }
        printf("\n");
    }
}

int main() {


    while (gets(str), str[0] != '#') {
        memset(sqr, 0, sizeof(int) * MAXN * MAXN);
        memset(ch, 0, sizeof(int) * MAXN);
        memset(record, 0, sizeof(int) * MAXN);

        processStr();
        num = 0;

        for(int i = 0; i < MAXN; ++i) {
            if (record[i]) {
                ch[num++] = i + 'A';
            }
        }
        //print();
        sort(ch, ch + num);

        int ans = 1000;
        do {
            //ch[0] = 'A'; ch[1] = 'B'; ch[2] = 'F'; ch[3] = 'C'; ch[4] = 'D'; ch[5] = 'E';
            //ch[6] = 'G'; ch[7] = 'H';
            //print();
            int band = 0;
            for (int step = num - 1; step > 0 ; --step) {
                for (int i = 0; i + step < num; ++i) {
                    if (sqr[ch[i] - 'A'][ch[i + step] - 'A']) {
                        band = step;
                        break;
                    }
                }
                if (band)
                    break;
            }

            if (band < ans) {
                ans = band;
                memcpy(record, ch, sizeof(char) * num);
                record[num] = '\0';
            }
        } while (next_permutation(ch, ch + num));

        for (int i = 0; i < num; ++i) {
            printf("%c ", record[i]);
        }
        printf("-> %d\n", ans);
    }

    return 0;
}

