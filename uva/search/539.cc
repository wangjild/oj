#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define eps 1e-8

using namespace std;
const int MAXN = 30;

int n, m, ans, tans;
int G[MAXN][MAXN];//存储地图
int vis[MAXN];//标记节点是否被走过

//搜索
int dfs(int pos , int max) {
    if(max > tans)//更新临时的tans
        tans = max;
    for (int i = 0; i < n; i++) {
        if (G[pos][i]) {
            --G[pos][i];//无向图每一条边只能走一次
            --G[i][pos];
            vis[pos] = 1;//标记节点被走过
            dfs(i , max+1);
            vis[pos] = 0;
            ++G[i][pos];
            ++G[pos][i];//状态的回溯
        }
    }
    return tans;//返回该点能走的最大值
}

void solve(){
    int i , j;
    int temp;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(G[i][j]){//遍历每一个点
                tans = 0;//初始化为0
                temp = dfs(i , 0);
                if(ans < temp)//更新最大的值
                    ans = temp;
            }
        }
    }  
}

//主函数
int main() {
    int x, y;
    while (scanf("%d%d%*c", &n, &m) && n && m) {
        memset(G, 0, sizeof (G));
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            G[x][y] = 1;//因为每一条边只能走一次，所以标记为1即可
            G[y][x] = 1;
        }
        ans = 0;
        solve();
        printf("%d\n", ans);
    }
    return 0;
} 
