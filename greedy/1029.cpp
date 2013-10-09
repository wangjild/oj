#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int coin[10001] = {0};

set<int> ls;
set<int> rs;

set<int> tls;
set<int> trs;

inline void findTrue(set<int> &main, set<int>& slave) {
    if (main.size() == 0 || slave.size() == 0)
        return ;

    set<int> diff;
    set<int>::iterator it = set_difference(main.begin(), main.end(), slave.begin(), slave.end(), diff.begin());
    diff.resize(it - diff.begin());

    for(it = diff.begin(); it < diff.end(); ++it) 
    {
        coin[*it] = 1;
    }
}

inline void remainFalse(set<int>& main, set<int>& slave) 
{
    set<int> same;
    set<int>::iterator it = set_union(main.begin(), main.end(), slave.begin(), slave.end(), same.begin());

    same.resize(it - same.begin());

    main.swap(same);
}

void unionCoin(set<int>& small, set<int>& big) 
{
    findTrue(ls, small);
    findTrue(rs, big);

    remainFalse(ls, small);
    remainFalse(rs, small);
}

void inline removeTrueCoin(set<int>& main, set<int>& left) 
{
    set<int>::iterator it;

    for (it = slave.begin(); it < slave.end(); ++it) 
    {
        if (coin[*it] == 1) 
            continue;
        main.erase(*it);
        coin[*it] = 1;
    }
}

void clearTrueCoin(set<int> &l, set<int>& r) {
    removeTrueCoin(ls, l);
    removeTrueCoin(rs, l);
    removeTrueCoin(ls, r);
    removeTrueCoin(rs, r);
}

inline void debug() {
#if DEBUG
    set<int>::iterator it;
    cout << "left: "
    for (it = ls.begin(); it < ls.end(); ++it) {
        cout << *it << ' ';
    }
    count << endl;

    cout << "right: "
    for (it = rs.begin(); it < rs.end(); ++it) {
        cout << *it << ' ';
    }
    count << endl;

#else 
#endif
}
int main() {
    int N, K;
    cin >> N >> K;

    int maxline = 2*K;
    int i;
    for (i = 0; i < maxline; i += 2) {
        int n, j;
        cin >> n;

        int maxcoin = 2*n;
        for (j = 0; j < n; ++j) {
            int idx;
            cin >> idx;
            tls.insert(idx);
        }

        for (; j < maxcoin; ++j) {
            int idx;
            cin >> idx;
            trs.insert(idx);
        }

        char c;
        cin >> c;

        switch (c) {
            case '<' :
                unionCoin(tls, trs);    
                break;
            case '>' :
                unionCoin(trs, tls);    
                break;
            case '=' :
                clearTrueCoin(tls, trs);
                break;
        }
    }
}
