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

sec_t section[2500000];
sec_t ans[2500000];

int n, an;

bool cmp(const sec_t& a, const sec_t& b) {
    if (a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
} 

int main () {
    int c;
    scanf("%d", &c);

    while (c--) {
        int l, r, M;
        scanf("%d", &M);
        while (scanf("%d%d", &l, &r), l || r) {
            section[n].l = l; section[n].r = r;
            n++;
        }
        sort(section, section + n, cmp);

        if (section[0].l > 0) {
            printf("0\n");
            continue;
        }

        if (section[0].l <= 0 && section[0].r >= M) {
            printf("1\n%d %d\n", section[0].l, section[0].r);
            continue;
        }
        an = 0;

        int leftmark = 0;
        int rightmark = 0;

        int cl = INT_MIN, cr = INT_MIN;
        rep(i, n) {
            if (section[i].l <= leftmark && section[i].r < leftmark)
                continue;
            else if (section[i].l <= leftmark && section[i].r >= leftmark) {
                if (cr < section[i].r) {
                    cl = section[i].l, cr = section[i].r;
                }
            } else { // section[i].l > leftmark
                if (cr < rightmark) 
                {
                    break;
                }

                ans[an].l = cl, ans[an].r = cr; an ++;
                leftmark = cl, rightmark = cr;
            }
        }

        if (an == 0 || ans[an - 1].r < M) {
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

