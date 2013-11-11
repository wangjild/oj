/*
只要对两个数组排序，然后比对完全相同就是YES，否则NO
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define MAXN 500010

int n , flag;
int loc[MAXN] , res[MAXN];

int solve(){
    sort(loc , loc+n);
    sort(res , res+n);
    return memcmp(loc, res, sizeof(int) * n);
}

int main(){
    //freopen("input.txt" , "r" , stdin);
    while(scanf("%d" , &n) && n) {
		long long suma = 0, sumb = 0;
        for(int i = 0 ; i < n ; i++) {
            scanf("%d %d" , &loc[i] , &res[i]);
			// suma += loc[i]; sumb += res[i];
		}
		if (n % 2) {
			printf("NO\n");
			continue;
		}
        if(solve() == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

