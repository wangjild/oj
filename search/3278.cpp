#include <cstdio>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100001
int F, C;
int ans = INT_MAX;

int step[MAX_N];
char path[MAX_N];

queue<int> que;
void bfs() {
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        if (cur == C)
        {
            printf("%d\n", step[cur]);
#ifdef WANGJING
            while (cur != F) {
                char c = path[cur];
                switch (c) {
                    case '+':
                        cur--;
                        printf("+ "); fflush(stdout);
                        break;
                    case '-':
                        cur ++;
                        printf("- "); fflush(stdout);
                        break;
                    case '*':
                        cur /= 2;
                        printf("* "); fflush(stdout);
                        break;
                }
            }
            printf("\n");
#endif
            return;
        }

        int nextstepnum = step[cur] + 1;
        int next = cur + 1;

        // f + 1
        if (next <= C && step[next] > nextstepnum) {
            que.push(next);
            step[next] = nextstepnum;
            path[next] = '+';
        }

        // f * 2
        next = cur * 2;
        if (next - 1 <= C && next > 0 
                && step[next] > nextstepnum) {
            que.push(next);
            step[next] = nextstepnum;
            path[next] = '*';
        }
        
        // f - 1
        next = cur - 1;
        if (next >= 0 && step[next] > nextstepnum) {
            que.push(next);
            step[next] = nextstepnum;
            path[next] = '-';
        }
    }
}

int main() {
    scanf("%d%d", &F, &C);

    if (F > C) {
        printf("%d\n", F - C);
        return 0;
    }

    fill(step, step + MAX_N, INT_MAX);
    que.push(F);
    
    step[F] = 0;
    path[F] = 0;    
    bfs();
}
