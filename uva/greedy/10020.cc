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

/****** TEMPLATE ENDS ******/
typedef struct sec{
    int l, r;
} sec_t;

sec_t section[10000];
sec_t ans[10000];

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
        //dump();
        if (n == 0 || section[0].l > 0) {
            printf("0\n");
            if (c) printf("\n");
            continue;
        }

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
            printf("0\n");
        } else {
            printf("%d\n", an);
            for (int i = 0; i < an; ++i) {
                printf("%d %d\n", ans[i].l, ans[i].r);
            }
        }
        if (c)
            printf("\n");
    }

}

