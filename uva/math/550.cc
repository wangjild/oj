#include <cstdio>

int main() {
	int k, m, n;

	while (scanf("%d%d%d", &k, &m, &n) != EOF) {
		int cnt = 1;
		int s=m*n;
		while (s != m) {
			s = s % k * n + s / k;
			cnt ++;
		}

		printf("%d\n", cnt);
	}
	return 0;
}
