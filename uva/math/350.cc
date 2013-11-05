#include <cstdio>
#include <cstring>

int flag[10001];

int main() {
	int Z, I, M, L;
	int c = 1;
	while (scanf("%d%d%d%d", &Z, &I, &M, &L), Z || I || M || L) {
		memset(flag, 0, sizeof(flag));

		int cnt = 1;
		do {
			flag[L] = cnt++;
			L = (Z * L + I) % M;
		} while (!flag[L]);

		printf("Case %d: %d\n", c++, cnt - flag[L]);
	}
	return 0;
}
