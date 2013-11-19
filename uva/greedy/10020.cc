/*
 *   Author:        wangjild <wangjild@gmail.com>
 *   Blog:          http://www.liloke.com/
 *   Github:        https://github.com/wangjild/oj
 *   File:          UVA10020.cc
 *   Lauguage:      c/cpp
 *   Date:          13-11-17 22:31:12
 *   Descripton:    
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)

typedef long long LL;
typedef unsigned long long ULL;
void intline2buf(int* , int);
void str2buf(const char*, int);
void printall();

/****** TEMPLATE ENDS ******/
typedef struct sec{
    int l, r;
} sec_t;

sec_t section[100000];
sec_t ans[100000];

int n, an;

bool cmp(const sec_t& a, const sec_t& b) {
    return a.l < b.l;
} 

void dump() {
    printf("******DUMP*******\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: (%d,%d)\n", i, section[i].l, section[i].r);
    }
    printf("******DOWN*******\n");
}

int main () {
    int c;
    scanf("%d", &c);

    while (c--) {
        int l, r, M;
        scanf("%d", &M);
        n = 0;
        while (scanf("%d%d", &l, &r), l || r) {
            if ((l < 0 && r <= 0) || (l >= M && r >= M))
                continue;
            section[n].l = l; section[n].r = r;
            n++;
        }
        sort(section, section + n, cmp);

        an = 0;
        int i = 0, left = 0, right = 0;
        
        while(i < n) {
            bool flag = false;
            while (i < n && section[i].l <= left) {
                if (section[i].r > right) {
                    ans[an].l = section[i].l;
                    right = ans[an].r = section[i].r;
                    flag = true;
                }
                ++i;
            }

            if (!flag) break;
            an ++;

            if (right >= M) break;
            left = right;
            --i;
        }
        
        if (right < M) {
            str2buf("0\n", 2);
        } else {
            int number[2];
            number[0] = an;
            intline2buf(number, 1);
            for (int i = 0; i < an; ++i) {
                number[0] = ans[i].l;
                number[1] = ans[i].r;
                intline2buf(number, 2);
            }
        }
        if (c)
            str2buf("\n", 1);
    }
    printall();
    return 0;
}

#include <cstdio>

#define likely(x) __builtin_expect(!!(x), 1)

#define unlikely(x) __builtin_expect(!!(x), 0)

const int MAXN = 50001;
int num[MAXN];

const int MAXS = 20 * MAXN + 1;
char buf[MAXS];

int analyse(char* buf, int len = MAXS) {
    int i;
    num[i = 0] = 0;
    bool flag = false;
	for (char *p = buf; *p && p - buf < len; ++p) {
		if (*p == ' ' || *p == '\n') {
            if (flag) {
                num[i] = 0 - num[i];
                flag = false;
            }
			num[++i] = 0;
        }
		else if(unlikely(*p == '-')) {
            flag = true;
        }
        else
			num[i] = num[i] * 10 + *p - '0';
	}
	return i;
}

int fastreadint() {
    int len = fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';

	return analyse(buf, len);
}

int bufidx = 0;
void double2buf(double val, int size) {
    bufidx += sprintf(buf + bufidx, "%.4f\n", val);
    buf[bufidx] = '\0';
}

void intline2buf(int *val, int intnum) {
    for (int i = 0; i < intnum; ++i) {
        if (likely(i)) bufidx += sprintf(buf + bufidx, " %d", val[i]);
        else bufidx += sprintf(buf+bufidx, "%d", val[i]);
    }
    bufidx += sprintf(buf+bufidx, "\n");
    buf[bufidx] = '\0';
}

void str2buf(const char* str, int len) {
    memcpy(buf + bufidx, str, len);
    bufidx += len;
    buf[bufidx] = '\0';
}

void printall() {
    printf("%s", buf);
}
