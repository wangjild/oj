#include <cstdio>
#include <cstring>
#include <limits.h>

#define MAX_N 25

int sqr[MAX_N][MAX_N];

int W, H;
int sx, sy, ex, ey;

int minimal = INT_MAX;

bool ok(int x, int y) {
    return x < H && x >= 0 && y < W && y >= 0;
}

int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void solve(int sx, int sy, int step) {

    /*
    printf("step %d:\n", step);
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            printf("%d ", sqr[i][j]);
        }
        printf("\n");
    }
    */

    // big than 10 step, discard
    if (step >= 10) return;

    // 4 direction
    for (int i = 0; i < 4; ++i) {
        int x = sx + d[i][0], y = sy + d[i][1];
        if (!ok(x, y) || sqr[x][y] == 1){
    //        printf("x:%d, y:%d\n", x, y);
            continue;
        }
        while (ok(x, y) && sqr[x][y] == 0) {
            x += d[i][0];
            y += d[i][1];
        }
        if (!ok(x, y))
            continue;

        if (sqr[x][y] == 1) {
            sqr[x][y] = 0;
            solve(x-d[i][0], y-d[i][1], step + 1);
            sqr[x][y] = 1;
        }

        if (sqr[x][y] == 3) {
            if (step + 1 < minimal)
                minimal = step + 1;
        }
    }
}

// int casnum = 0;

int main() {

    memset(sqr, 1, sizeof(int) * MAX_N * MAX_N);
    while (scanf("%d%d", &W, &H), !(W == 0 && H == 0)) {
   //     if ( ++ casnum % 5 == 1) {
   //         printf("(%d~%d):\n", casnum, casnum + 4);
   //     }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%d", &sqr[i][j]);
                if (sqr[i][j] == 2) {
                    sx = i;
                    sy = j;
                    sqr[i][j] = 0;
                }
                if (sqr[i][j] == 3) {
                    ex = i;
                    ey = j;
                }
            }
        }

        /*
        for(int i = 0; i <= H+1; ++i) {
            for(int j = 0; j <= W+1; ++j) {
                printf("%c", sqr[i][j]);
            }
            printf("\n");
        }*/

        minimal = INT_MAX;
        solve(sx, sy, 0);
        if (minimal < INT_MAX)
            printf("%d\n", minimal);
        else
            printf("-1\n");
    }

    return 0;
}
