 /*
 *   Author:        wangjild <wangjild@gmail.com>
 *   Blog:          http://www.liloke.com/
 *   Github:        https://github.com/wangjild/oj
 *   File:          UVA10954.cc
 *   Lauguage:      c/cpp
 *   Date:          13-11-19 18:54:06
 *   Descripton:    
 */
#include <climits>
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

/****** TEMPLATE ENDS ******/

priority_queue<long long, vector<long long>, greater<long long> > que;

int main() {
    int c;
    while (scanf("%d", &c), c) {
        for (int i = 0; i < c; ++i) {
            long long num;
            scanf("%lld", &num);
            que.push(num);
        }

        long long ans = 0;
        while(que.size()) {
            if (que.size() == 1) {
                printf("%lld\n", ans); que.pop();
            } else {
                long long a = que.top(); que.pop();
                a += que.top(); que.pop();
                que.push(a);
                ans += a;
            }
        }
    }
    return 0;
}
