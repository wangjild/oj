#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <algorithm>

using namespace std;


int main() {
    int casenum;
    scanf("%d", &casenum);

    while (casenum --) {
        int length, antnums;
        scanf("%d%d", &length, &antnums);

        int minpos = INT_MAX;
        int maxpos = -1;

        int midmin = INT_MAX;
        int idx = -1;
        int pos = -1;
        for(int i = 0; i < antnums; ++i) 
        {
            scanf("%d", &pos);
    
            if (pos < minpos) minpos = pos;
            if (pos > maxpos) maxpos = pos;

            if (abs(length - 2*pos) < midmin) {
                midmin = abs(length - 2*pos);
                idx = pos;
            }
        }

        printf("%d ", min(length - idx, idx));
        printf("%d\n", max(length - minpos, maxpos));
    }
}
