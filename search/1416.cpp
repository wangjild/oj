#include <cstdio>
#include <cstring>
#include <limits.h>

inline int swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

#define MAX_N 10
int arr[MAX_N];
int len, sum, min, solve;

int T, number;

int idx = 0;
int res[MAX_N];

int ansi = 0;
int ans[MAX_N];

void dfs(int pos, int sum) {

    // error
    if (sum > T)
        return ;

    if (pos == len) {
        // log
        if (T - sum < min) {
            min = T - sum;
            solve = 0;
            for(int i = 0; i < idx; ++i) {
                ans[i] = res[i];
//                printf("%d ", res[i]);
            }
//            printf("\n");
            ansi = idx;
        }
        if (T - sum == min) {
            solve ++;
        }
        return ;
    }

    res[idx] = arr[pos];
    sum += arr[pos];
    idx ++;
    dfs(pos+1, sum);
    idx --;
    sum -= arr[pos];
    res[idx] = 0;
    
    if (idx > 0) {
        sum = sum - res[idx-1] + 10 * res[idx-1] + arr[pos];
        res[idx-1] = res[idx-1]*10 + arr[pos];  // 拼接
        dfs(pos+1, sum);
        sum = sum - res[idx-1];
        res[idx-1] = (res[idx-1] - arr[pos])/10; // 恢复
        sum = sum + res[idx-1];
    }
}

int main() {

    while(scanf("%d%d", &T, &number), T || number) {
        len = 0; sum = 0; min = INT_MAX; solve = 0;

        int t = number;
        while (t) {
            arr[len++] = t % 10;
            t /= 10;
        }

        for (int i = 0; i < len / 2; ++i) {
            swap(arr[i], arr[len - i - 1]);
        }

        dfs(0, 0);

        if (solve > 1)
        {
            printf("rejected\n", solve);
            continue;
        }

        if (solve == 0) {
            printf("error\n");
            continue;
        }

        printf("%d ", T - min);
        for(int i = 0; i < ansi; ++i) {
            printf("%d", ans[i]);
            if (i < ansi - 1)
                printf(" ");
        }
        printf("\n");

    }

    return 0;
}
