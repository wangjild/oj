#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int num[11];
int vis[11];

int greedy(int n) {
    sort(num, num + n);

    int big = 0, small = 0;

    if (num[0] == 0)
    {
        big = num[1];
        swap(num[0], num[1]);
    } else
        big = num[0];

    int s = 1, t = n - 1;
    while(s < t) {
        big = big * 10 + num[s++];
        small = small * 10 + num[t--];
    }

    return big - small;
}

int tmp[11];

int ans;
int dfs(int step, int ret, int N) {
    if (step == N / 2) 
    {
        int len = 0;
        int b = 0;
        for(int i = 0; i < N; ++i) 
        {
            if (!vis[i])
            {
                tmp[len++] = num[i];
                b = b * 10 + num[i];
            }
        }

        if (tmp[0] != 0) 
        {
            ans = min(ans, abs(ret - b));
        }

        while(next_permutation(tmp, tmp+len)) {
            b = 0;
            for(int i = 0; i < len; ++i) {
                b = b * 10 + tmp[i];
            }
            if (tmp[0] != 0)
                ans = min(ans, abs(ret - b));
        }


    }

    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            if (num[i] == 0 && step == 0 && N > 3)
                continue;
            vis[i] = 1;
            dfs(step + 1, ret*10 + num[i], N);
            vis[i] = 0;
        }
    }
}

void solve(int n) {
    
    ans = INT_MAX;

    if (n % 2 == 1)
    {
        ans = greedy(n);
        return ;
    }

    if (n == 2)
        ans = abs(num[1] - num[0]);
    else 
        dfs(0, 0, n);
}

int main() {
    int C;

    for (scanf("%d ", &C); C; C--) 
    {
        memset(num, 0, sizeof(int) * 11);
        
        int n = 0;

        char ch;
        while((ch = getchar()) != '\n') {
            if (ch == ' ')
                continue;
            num[n++] = ch - '0';
        }

        memset(vis, 0, sizeof(int) * 11);
        solve(n);
        printf("%d\n", ans);
    }
}
