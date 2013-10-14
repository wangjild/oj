#include <cstdio>
#include <queue>

using namespace std;
int N;

long long bfs() {
    queue<long long> que;

    que.push(1);
    while(true) {
        long long r = que.front(); que.pop();
        if (r % N == 0)
            return r;
        long long next = 10 * r;
        que.push(next);
        que.push(next + 1);
    }
}

int main() {
    while (scanf("%d", &N), N) {
        printf("%lld\n", bfs());
    }

    return 0;
}
