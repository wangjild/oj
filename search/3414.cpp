#include <cstdio>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX_N 101

// 下标x表示a壶中目前有x份水
// 下标y表示b壶中目前有y份水
// price[x][y] 存的是操作数
int price[MAX_N][MAX_N];

// 输出路径
char path[2*MAX_N][16];

int a, b, target;

typedef struct point {
    int x, y;
} point_t;

int idx = 0;

queue<point_t> que;

int bfs() {
    while(!que.empty()) {
        point_t p = que.front(); que.pop();
        
        if (p.x == target || p.y == target) {
            return price[p.x][p.y];
        }

        point_t next;
        
        // Fill a
        next.x = a; next.y = p.y;
        if (price[next.x][next.y] > price[p.x][p.y] + 1) {
            price[next.x][next.y] = price[p.x][p.y] + 1;
            sprintf(path[price[next.x][next.y]+idx], "FILL(1)");
            que.push(next);
        }

        // Fill b
        next.x = p.x; next.y = b;
        if (price[next.x][next.y] > price[p.x][p.y] + 1)
        {
            price[next.x][next.y] = price[p.x][p.y] + 1;
            sprintf(path[price[next.x][next.y]+idx], "FILL(2)");
            que.push(next);
        }

        // Drop a
        if (price[0][p.y] > price[p.x][p.y] + 1)
        {
            price[0][p.y] = price[p.x][p.y] + 1;
            sprintf(path[price[0][p.y]+idx], "DROP(1)");
            next.x = 0; next.y = p.y;
            que.push(next);
        }

        // Drop b
        if (price[p.x][0] > price[p.x][p.y] + 1)
        {
            price[p.x][0] = price[p.x][p.y] + 1;
            sprintf(path[price[p.x][0]+idx], "DROP(2)");
            next.x = p.x; next.y = 0;
            que.push(next);
        }

        // Fill a->b
        next.x = p.x - (b - p.y); next.x = next.x < 0 ? 0 : next.x;
        next.y = p.y + p.x - next.x;
        if (price[next.x][next.y] >  price[p.x][p.y] + 1) {
            price[next.x][next.y] =  price[p.x][p.y] + 1;
            sprintf(path[price[next.x][next.y]+idx], "POUR(1,2)");
            que.push(next);
        }

        // Fill b->a
        next.y = p.y - (a - p.x); next.y = next.y < 0 ? 0 : next.y;
        next.x = p.x + p.y - next.y;

        if (price[next.x][next.y] >  price[p.x][p.y] + 1) {
            price[next.x][next.y] =  price[p.x][p.y] + 1;
            sprintf(path[price[next.x][next.y]+idx], "POUR(2,1)");
            que.push(next);
        }
    }

    return INT_MAX;
}

int main () {
    scanf("%d%d%d", &a, &b, &target);

    for(int i = 0; i < MAX_N; ++i) {
        fill (price[i], price[i] + MAX_N, INT_MAX);
    }

    // 从a出发
    idx = 0;
    price[0][0] = 0;
    price[a][0] = 1;
    sprintf(path[1+idx], "FILL(1)");
    point_t p; p.x = a; p.y = 0;
    que.push(p);
    int mina = bfs();
    
    while(!que.empty()) que.pop();
    for(int i = 0; i < MAX_N; ++i) {
        fill (price[i], price[i] + MAX_N, INT_MAX);
    }

    // 从b出发
    idx = MAX_N;
    price[0][0] = 0;
    price[0][b] = 1;
    sprintf(path[1+idx], "FILL(2)");
    p.x = 0; p.y = b;
    que.push(p);
    int minb = bfs();

    if (mina == INT_MAX && minb == INT_MAX) {
        printf("impossible\n");
        return 0;
    }

    if (mina < minb) {
        idx = 0;
    }
    int mini = min(mina, minb);
    printf("%d\n", mini);
    for (int i = 1; i <= mini; ++i) {
        printf("%s\n", path[i+idx]);
    }

    return 0;
}
