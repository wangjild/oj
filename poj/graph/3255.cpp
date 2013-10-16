#include <vector>
#include <cstdio>
#include <cstdlib>
#include <limits.h>

#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge_e {
    int to, cost;
} edge;

#define MAX_N 5001

int N, R;
vector<edge> G[MAX_N];

int dist[MAX_N];
int dist2[MAX_N];

int main() {

    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P> > que;
    scanf("%d%d", &N, &R);
    
    int from, to, cost;
    while (R--)
    {
        scanf("%d%d%d", &from, &to, &cost);
        edge e; e.to = to; e.cost = cost;
        G[from].push_back(e);
    }

    fill(dist, dist + N + 1, INT_MAX);
    fill(dist2, dist2 + N + 1, INT_MAX);

    dist[1] = 0;
    que.push(P(0, 1));

    while (!que.empty()) {
        P p = que.top(); que.pop();

        int v = p.second, d = p.first;

        if (dist2[v] < d) continue;

        for (int i = 0; i < G[v].size(); ++i) {
            edge &e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2) {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2) {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }


        }
        
        printf("cost1: ");
        for (int i = 0; i < N + 1; ++i) {
            printf("%10d ", dist[i]);
        }
        printf("\ncost2: ");
        for (int i = 0; i < N + 1; ++i) {
            printf("%10d ", dist2[i]);
        }   
        printf("\n");
       
    }

    printf("%d\n", dist2[N]);
    return 0;
}
