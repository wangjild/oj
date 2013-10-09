#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int mark[1001] = {0};
int tmp[1001] = {0};

int left_arr[1001] = {0};
int right_arr[1001] = {0};

inline void debug(const set<int>& falseCoin) {
#if WANGJING_DEBUG
    cout << "false coin: ";
    for(set<int>::iterator it = falseCoin.begin(); it != falseCoin.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
#else 
#endif
}

void debug(int* arr, int size, int l) {
#ifdef WANGJING_DEBUG
    if (l) 
        cout << "left: ";
    else
        cout << "right: ";
    for(int i = 0; i < size; ++i) {
        cout<< arr[i] << " ";
    }
    cout << endl;
#else
#endif
}

void intersectionCoin(set<int>& falseCoin, int* coin, int maxcoin, bool l) {

    int middle = maxcoin / 2;
    for(int i = 0; i < middle; ++i) {
        if (l) {
            ++left_arr[coin[i]];
            if (right_arr[coin[i]] != 0) {
                falseCoin.erase(coin[i]);
            }
        } else {
            ++right_arr[coin[i]];
            if (left_arr[coin[i]] != 0) {
                falseCoin.erase(coin[i]);
            }
        }
    }
    for(int i = middle; i < maxcoin; ++i) {
        if (l) {
            ++right_arr[coin[i]];
            if (left_arr[coin[i]] != 0) {
                falseCoin.erase(coin[i]);
            }
        } else {
            ++left_arr[coin[i]];
            if (right_arr[coin[i]] != 0) {
                falseCoin.erase(coin[i]);
            }
        }
    }
    debug(falseCoin);


    set<int> tmp(coin, coin + maxcoin);

    set<int> same;
    set_intersection(falseCoin.begin(), falseCoin.end(), tmp.begin(), tmp.end(), insert_iterator<set<int> >(same, same.end()));

    falseCoin.swap(same);
}

void clearTrueCoin(set<int>& falseCoin, int* arr, int maxcoin) {

    set<int> tmp(arr, arr + maxcoin);
    set<int> same;
#ifdef WANGJING_DEBUG 
    cout<<"Before ClearTrue: ";
    debug(falseCoin);
#endif
    set_difference(falseCoin.begin(), falseCoin.end(), tmp.begin(), tmp.end(), insert_iterator<set<int> >(same, same.end()));

    falseCoin.swap(same);
#ifdef WANGJING_DEBUG
    cout<<"After ClearTrue: ";
    debug(falseCoin);
#endif
}

int main() {

    memset(left_arr, 0, sizeof(int) * 1001);
    memset(right_arr, 0, sizeof(int) * 1001);

    int N, K;
    cin >> N >> K;

    int i;
    for(i = 0; i < N; ++i) {
        mark[i] = i + 1;
    }

    set<int> falseCoin(mark, mark + N);

    int maxline = 2*K;
    for (i = 0; i < maxline; i += 2) {
        int n, j;
        cin >> n;
        int maxcoin = 2*n;
        for (j = 0; j < maxcoin; ++j) {
            int idx;
            cin >> idx;
            tmp[j] = idx;
        }

        char c;
        cin >> c;

        switch (c) {
            case '<' :
                intersectionCoin(falseCoin, tmp, maxcoin, true);
                break;
            case '>' :
                intersectionCoin(falseCoin, tmp, maxcoin, false);    
                break;
            case '=' :
                clearTrueCoin(falseCoin, tmp, maxcoin);
                break;
        }

        debug(falseCoin);
    }

    if (falseCoin.size() == 1) {
        cout << *(falseCoin.begin()) << endl;
    } else {
        cout <<0<< endl;
    }
}
