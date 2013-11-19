 /*
 *   Author:        wangjild <wangjild@gmail.com>
 *   Blog:          http://www.liloke.com/
 *   Github:        https://github.com/wangjild/oj
 *   File:          UVA10714.cc
 *   Lauguage:      c/cpp
 *   Date:          13-11-19 16:08:44
 *   Descripton:    
 */
//#include <cstdint>
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
const int maxn = 1000001;

int main () {
    
    int c;
    scanf("%d", &c);

    while (c--) {
        int l, m;
        scanf ("%d%d", &l, &m);
        double mid = l / 2;
        int minval = INT_MAX, maxval = INT_MIN, pos, midval = INT_MAX, midpos;
        for (int i = 0; i < m; ++i) { 
            scanf("%d", &pos);
            minval = min(minval, pos);
            maxval = max(maxval, pos);
            double dis = fabs((double) pos - mid);
            if (dis < midval) {
                midval = dis;
                midpos = pos;
            }
        }

        printf("%d %d\n", min(midpos, l - midpos), max(l - minval, maxval));
    }
    return 0;
}
