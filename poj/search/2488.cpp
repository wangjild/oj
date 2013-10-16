#include <cstdio>
#include <cstring>

int p, q;

int total;

#define MAX_N 26
int sqr[MAX_N][MAX_N];

inline bool ok(int x, int y) {
    return x >= 0 && x < p && y >= 0 && y < q;
}

// 字典序
int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}; 
int path[MAX_N*MAX_N][2];

bool output = false;

void dfs(int step, int x, int y) {
    if (step == total) {
        for (int i = 0; i < total; ++i) {
            printf("%c%c", path[i][0], path[i][1]);
        }
        printf("\n");
        output = true;
        return ;
    }

    for(int i = 0; i < 8 && output == false; ++i) {
        int newx = x + dir[i][0];
        int newy = y + dir[i][1];

        if (!ok(newx, newy) || sqr[newx][newy])
            continue;
        sqr[newx][newy] = 1;
        path[step][0] = 'A' + newx;
        path[step][1] = '1' + newy;
        dfs(step + 1, newx, newy);
        sqr[newx][newy] = 0;
    }
}

int main() {
    int C;

    scanf("%d", &C);
    for(int i = 1; i <= C; ++i) {
        scanf("%d%d", &q, &p);
        total = p * q;
        memset(sqr, 0, sizeof(int) * MAX_N * MAX_N);

        sqr[0][0] = 1;
        path[0][0] = 'A';
        path[0][1] = '1';
        int step = 1;
        
        printf("Scenario #%d:\n", i);
        output = false;
        dfs(step, 0, 0);
        if (!output) {
            printf("impossible\n");
        }
        if (i != C) {
            printf("\n");
        }
    }

}
