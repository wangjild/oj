 /*
 *   Author:        wangjild <wangjild@gmail.com>
 *   Blog:          http://www.liloke.com/
 *   Github:        https://github.com/wangjild/oj
 *   File:          UVA311.cc
 *   Lauguage:      c/cpp
 *   Date:          13-11-16 23:38:47
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

inline long long max(long long a, long long b) { return (a) > (b) ? a : b;}

void solve(long long * arr, long long& ans) {
    if (arr[6]) {
        ans += arr[6]; arr[6] = 0;
    }

    if (arr[5]) {
        ans += arr[5]; arr[1] -= 11*arr[5]; arr[5] = 0; 
        arr[1] = max(0, arr[1]);
    }

    // process 4
    if (arr[4]) {
        ans += arr[4];
        arr[2] -= 5*arr[4];
        if (arr[2] < 0) {
            arr[1] += 4*arr[2];
            arr[1] = max(0, arr[1]);
            arr[2] = 0;
        }
    }

    // process 3
    if (arr[3]) {
        ans += arr[3]/4;
        long long remain = arr[3] % 4;
        if (remain) {
            ans += 1;
            // process remain 2
            if (remain == 3) {
                arr[2] -= 1;
                if (arr[2] < 0) {
                    arr[1] += 4*arr[2];
                    arr[2] = 0;
                    arr[1] = max(0, arr[1]);
                }
                arr[1] -= 5;
            } else if (remain == 2) {
                arr[2] -= 3;
                if (arr[2] < 0) {
                    arr[1] += 4*arr[2];
                    arr[2] = 0;
                    arr[1] = max(0, arr[1]);
                }
                arr[1] -= 6;
            } else if (remain == 1) {
                arr[2] -= 5;
                if (arr[2] < 0) {
                    arr[1] += 4*arr[2];
                    arr[2] = 0;
                    arr[1] = max(0, arr[1]);
                }
                arr[1] -= 7;
            }
        }
    
    }

    if (arr[2] > 0) {
        ans += arr[2] / 9;
        arr[2] %= 9;
        if (arr[2] > 0) {
            ans += 1;
            arr[1] -= (36 - 4*arr[2]);
            arr[1] = max(0, arr[1]);
        }
    }

    if (arr[1] > 0) {
        ans += arr[1] / 36;
        if (arr[1] % 36 > 0) ans += 1;
    }


}

/****** TEMPLATE ENDS ******/
int main () {
    long long arr[7] = {0};
    long long lastline[7] = {0,0,0,0,0,0,0};
    while (scanf("%lld%lld%lld%lld%lld%lld", &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6])) {
        long long ans = 0;
         if (memcmp(arr, lastline, sizeof(arr)) == 0) {
            break;
         }
         solve(arr, ans);
         printf("%lld\n", ans);
    }
}
