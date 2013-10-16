#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

int map[10][10];
set<int> s;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool ok (int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

void dfs (int x, int y, int r, int k){
    if (k == 6) {
        s.insert(r);
        return;
    }
    r = r * 10 + map[x][y];

    for (int i = 0; i < 4; ++i) {
        x += dir[i][0]; y += dir[i][1];
        if (ok(x, y)) {
            dfs(x, y, r, k + 1);
        }
        x -= dir[i][0]; y -= dir[i][1]; 
    }
}

int main(){

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            scanf("%d", &map[i][j]);
        }
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            dfs(i, j, 0, 0);
        }

    printf("%d\n",s.size());
    return 0;
}

