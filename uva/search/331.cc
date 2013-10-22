#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
const int MAXN = 1000;

int n, ans;
int arr[5];

//判断函数

int judge() {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

//递归函数

void dfs() {
    if (judge()) {
        ++ans;//序列已经排好
        return;
    }
    for (int k = 0; k < n - 1; k++) {//这里每一次都从0开始搜索
        if (arr[k] > arr[k + 1]) {
            swap(arr[k], arr[k + 1]);
            dfs();
            swap(arr[k], arr[k + 1]);//状态的回溯
        }
    }
}

int main() {
    int cnt = 1;
    while (scanf("%d", &n) && n) {
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        if (!judge())
            dfs();
        printf("There are %d swap maps for input data set %d.\n", ans, cnt);
        ++cnt;
    }
    return 0;
}

