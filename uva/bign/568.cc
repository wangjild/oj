#include <cstdio>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		long m = 1;
		for (int i = 1; i <= n; ++i) {
			m *= i;
			while ( m % 10 == 0)
				m /= 10;
			m %= 100000;
		}

		printf("%5d -> %d\n", n, m % 10);
	}

	return 0;
}
