#include <map>
#include <cstdio>

using namespace std;

#define MAX_PAGE 1000000+1
map<int, int> summer;

int page[MAX_PAGE];
int P;

int main() {
    scanf("%d", &P);
    for(int i = 0; i < P; ++i) {
        scanf("%d", &page[i]);
        summer.insert(pair<int, int>(page[i], 0));
    }

    int snum = summer.size();
    int count = 0;

    int s = 0, t = 0; 
    int res = P;
    while (true) {
        while (t < P && count < snum) {
            if (summer[page[t++]] ++ == 0) {
                ++count;
            }
        }

        if (count < snum) break;

        res = min(res, t-s);

        if (--summer[page[s++]] == 0) {
            count --;
        }
    
    }

    printf("%d\n", res);
}
