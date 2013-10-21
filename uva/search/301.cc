#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct sec_t {
    int s;
    int d;
    int p;
    /*
    bool operator() (const sec_t& a, const sec_t& b) {
        if (a.s < b.s)
            return true;
        else if (a.s == b.s) {
            return a.d > b.d;
        }
        return false;
    }*/
};

bool func(const sec_t& a, const sec_t& b) {
    if (a.s < b.s)
        return true;
    else if (a.s == b.s) {
         return a.d > b.d;
    }

    return false;
}

vector<sec_t> v;

#define MAXN 23
int sqr[MAXN][MAXN];

int N; // capacity of bus
int M; // total station
int O; // number of order

int maxval = 0, mins, mind, maxs, maxd;
void print();

void dfs(vector<sec_t>::iterator it, int income) {

    if (it == v.end()) {
        maxval = max(income, maxval);
        return ;
    }
    // has "have" sit remaining
    print();
    int remain = sqr[(*it).s][(*it).d];
    int have = remain > (*it).p ? remain - (*it).p : remain;

    printf("income%d start:%d dist:%d remain:%d have:%d\n", income, (*it).s, (*it).d, remain, have);
    for (int i = have; i >= 0; ++i) {
        income += i * (*it).d;
        for(int start = (*it).d; start < (*it).s + (*it).d; ++start)
            for(int j = start; j < (*it).s + (*it).d; ++j)
                sqr[i][j] -= have;
        dfs(++it, income);
        for(int start = (*it).d; start < (*it).s + (*it).d; ++start)
            for(int j = start; j < (*it).s + (*it).d; ++j)
                sqr[(*it).s][j] += have;
        income -= i * (*it).d;
    }
}

void print() {
    for(int i = mins; i <= maxs; ++i) {
        for(int j = mind; j <= maxd; ++j) {
            printf("%d ", sqr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    while (scanf("%d%d%d", &N, &M, &O), N || M || O) {

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                sqr[i][j] = N;

        maxval = 0;
        v.clear();
        for(int i = 0; i < O; ++i) {
            int s, e, o;
            scanf("%d%d%d", &s, &e, &o);
            sec_t tmp; tmp.s = s; tmp.d = e - s; tmp.p = o;
            mins = min(s, mins);
            mind = min(mind, tmp.d);
            maxs = max(s, maxs);
            maxd = max(maxd, tmp.d);
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), func);
        dfs(v.begin(), 0);
        printf("%d\n", maxval);
    } 
}
