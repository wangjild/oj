#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX_N 400

int sqr[MAX_N][MAX_N];

int M;

class point_t {
    public :
        int x, y;
        point_t(int _x, int _y) : x(_x), y(_y) {} 
        point_t() : x(0), y(0) {}
};

multimap<int, point_t> seq;
queue<point_t> que;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

inline bool ok(int x, int y) {
    return x >= 0 && x < MAX_N && y >= 0 && y < MAX_N;
}

int cx = 0, cy = 0;

typedef multimap<int, point_t>::iterator point_it;

void print();

void solve() {

    while (!que.empty()) {

        point_t cp = que.front(); que.pop();
        cx = cp.x; cy = cp.y;

        // 已经填充过了
        pair<point_it, point_it> erit; // equal_range iterator
        erit = seq.equal_range(sqr[cx][cy]);
        for(point_it it = erit.first; it != erit.second; ++it) {
            int x = (*it).second.x, y = (*it).second.y;

            sqr[x][y] = INT_MAX;
            for(int i = 0; i < 4; ++i) {
                int newx = x + dir[i][0], newy = y + dir[i][1];
                if (!ok(newx, newy))
                    continue;
                sqr[newx][newy] = INT_MAX;
            }
            seq.erase(it);
        }

        // dead
        if (sqr[cx][cy] == INT_MAX) 
            continue ;

        //printf("%d %d %d\n", cx, cy, sqr[cx][cy]);
        for(int i = 0; i < 4; ++i) {
            int nextx = cx + dir[i][0], nexty = cy + dir[i][1];
            if ((nextx == 0 && nexty == 0) // 下一个点不能为 起始点
                    || !ok(nextx, nexty) // 出界
                    || (sqr[nextx][nexty] != 0 && sqr[nextx][nexty] <= sqr[cx][cy] + 1) // 非0 但是小于当前秒数
                    || sqr[nextx][nexty] == INT_MAX)
                continue;
            sqr[nextx][nexty] = sqr[cx][cy] + 1;
            point_t p(nextx, nexty);
            que.push(p);
        }
    }

    for(point_it it = seq.begin(); it != seq.end(); ++it) {
        int x = (*it).second.x, y = (*it).second.y;
        sqr[x][y] = INT_MAX;
        for(int i = 0; i < 4; ++i) {
            int newx = x + dir[i][0], newy = y + dir[i][1];
            if (!ok(newx, newy))
                continue;
            sqr[newx][newy] = INT_MAX;
        }
    }
}

int main() {
    scanf("%d", &M);

    int x, y, t;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &x, &y, &t);
        point_t p; p.x = x; p.y = y;
        seq.insert(pair<int, point_t>(t, p));
    }

    // 重置sqr图
    memset(sqr, 0, sizeof(int) * MAX_N * MAX_N);
    point_t p(0, 0);
    que.push(p);

    // 广搜
    solve();

    //print();
    if (sqr[0][0] == 0) {
        printf("0\n");
        return 0;
    }

    int minimal = INT_MAX;
    for (int i = 0; i < MAX_N; ++i) {
        for(int j = 0; j < MAX_N; ++j) {
            if (sqr[i][j] < minimal && sqr[i][j] != 0)
                minimal = sqr[i][j];
        }
    }

    printf("%d\n", minimal < INT_MAX ? minimal : -1);

    return 0;
}

void print() {
    printf("square:\n");
    for (int i = 0; i < MAX_N; ++i) {
        for(int j = 0; j < MAX_N; ++j) {
            printf("%10d ", sqr[i][j]);
        }
        printf("\n");
    }
}
