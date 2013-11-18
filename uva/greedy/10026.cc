 /*
 *   Author:        wangjild <wangjild@gmail.com>
 *   Blog:          http://www.liloke.com/
 *   Github:        https://github.com/wangjild/oj
 *   File:          UVA10026.cc
 *   Lauguage:      c/cpp
 *   Date:          13-11-16 23:13:08
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
struct Task {
    int t;
    int v;
    int num;
} task[1005];

int cmp(const Task& a, const Task& b) {
    if(a.t * b.v != b.t * a.v)
        return a.t * b.v < b.t * a.v;
    else
        return a.num < b.num;
}

int main() {
#ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int c;
    scanf("%d", &c);
    while(c--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &task[i].t, &task[i].v);
            task[i].num = i+1;
        }
        sort(task, task+n, cmp);
        for(int i = 0; i < n-1; i++)
            printf("%d ", task[i].num);
        printf("%d\n", task[n-1].num);
        if(c)
            printf("\n");
    }
    return 0;
}
