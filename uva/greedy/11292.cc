#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int dragon[20001];
int knight[20001];

int main() {
	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &dragon[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &knight[i]);
		}

		sort(dragon, dragon + n);
		sort(knight, knight + m);

		int i = 0, j = 0, ans = 0;
		while (i < n && j < m) {
			if (dragon[i] > knight[j]) {
				j++;
				continue;
			}
			ans += knight[j++], i++;
		}
		i == n ? printf("%d\n", ans) : printf("Loowater is doomed!\n");
	}
	return 0;
	
}
