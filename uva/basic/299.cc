#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 51
int arr[MAXN];

int len;

int main() {
    int c; scanf("%d", &c);

    while (c--) {
        scanf("%d", &len);
        for (int i = 0; i < len; ++i) {
            scanf("%d", &arr[i]);
        }

        int ans = 0;
        for(int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                    ++ans;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
    return 0;
}
