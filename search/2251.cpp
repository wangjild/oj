#include <cstdio>
#include <limits.h>
#include <queue>

using namespace std;


int L, R, C;

inline bool ok(int l, int r, int c) {
    return l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C;
}

int dir[6][3] = {
    {0, -1, 0}, 
    {0, 1, 0}, 
    {0, 0, -1}, 
    {0, 0, 1}, 
    {1, 0, 0}, 
    {-1, 0, 0}};

#define MAX_N 40
int cube[MAX_N][MAX_N][MAX_N];

typedef struct point {
    int l, r, c;
} point_t;

queue<point_t> que;

void print();

int sl, sr, sc;
int el, er, ec;

void bfs() {
    while (!que.empty()) {
        point_t cur = que.front(); que.pop();
//        printf("l:%d r:%d c:%d\n", cur.l, cur.r, cur.c);
        if (cur.l == el && cur.r == er && cur.c == ec) {
            printf("Escaped in %d minute(s).\n", cube[cur.l][cur.r][cur.c]);
            return ;
        }

        for (int i = 0; i < 6; ++i) {
            point_t next;
            next.l = cur.l + dir[i][0];
            next.r = cur.r + dir[i][1];
            next.c = cur.c + dir[i][2];

            // can't cross
            if (!ok(next.l, next.r, next.c) || cube[next.l][next.r][next.c] == INT_MAX) {
                continue;             
            }

            // visited
            if (cube[next.l][next.r][next.c] 
                    > cube[cur.l][cur.r][cur.c] + 1) {
                cube[next.l][next.r][next.c] = 
                    cube[cur.l][cur.r][cur.c] + 1;
                que.push(next);
            }
        }
    }

    printf("Trapped!\n");
}


int main() {

    while (scanf("%d%d%d", &L, &R, &C), L||R||C) { 
        getchar(); // get rid of '3 4 5\n'

        for(int l = 0; l < L; ++l) {
            for(int r = 0; r < R; ++r) {
                for(int c = 0; c < C; ++c) {
                    char ch = getchar();
                    switch (ch) {
                        case '.' :
                            cube[l][r][c] = INT_MAX - 1;
                            break;
                        case 'S' :
                            sl = l; sr = r; sc = c;
                            cube[l][r][c] = 0;
                            break;
                        case 'E' :
                            el = l; er = r; ec = c;
                            cube[l][r][c] = INT_MAX - 1;
                            break;
                        case '#' :
                            cube[l][r][c] = INT_MAX;
                    }
                }
                getchar(); // get rid of 'S....\n' 
            }
            getchar(); // get rid of '\n'
        }

        // print();
        point_t p; p.l = sl; p.r = sr; p.c = sc; 
        que.push(p);
        bfs();
    }

}

void print() {
    for (int l = 0; l < L; ++l) {
        for (int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                printf("%d", cube[l][r][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
