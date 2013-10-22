#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

struct sec_t {
    int s;
    int e;
    int p;
};

#define MAXN 23
sec_t v[MAXN];
int sqr[MAXN];

int N; // capacity of bus
int M; // total station
int O; // number of order

int maxval = 0, mins, mind, maxs, maxd;

bool ok(int s, int e) {
    for(int i = s; i < e; ++i) {
        if (v[i].p + sqr[i] > N)
            return false;
    }
    return true;
}

void dfs(int it, int income) {

    maxval = max(maxval, income);
   
    while (it < O) {
        if (!ok(v[it].s, v[it].e)) {
            it ++;
            continue;
        } 
        income += v[it].p * (v[it].e - v[it].s);
        for (int i = v[it].s; i < v[it].e; ++i) {
            sqr[i] += v[it].p;
        }
        dfs(it + 1, income);
        for (int i = v[it].s; i < v[it].e; ++i) {
            sqr[i] -= v[it].p;
        }
        income -= v[it].p * (v[it].e - v[it].s);
        it ++;
    }
}

int main() {
    while (scanf("%d%d%d", &N, &M, &O), N || M || O) {

        memset(sqr, 0, sizeof(int) * MAXN);
        maxval = 0;
        for(int i = 0; i < O; ++i) {
            int s, e, o;
            scanf("%d%d%d", &v[i].s, &v[i].e, &v[i].p);
        }

        sort(v, v + O, func);
        dfs(0, 0);
        printf("%d\n", maxval);
    } 
}
