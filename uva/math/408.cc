#include <cstdio>
#include <cstring>

char flag[10000001];

int main() {
	long step, mod;
	while (scanf("%ld%ld", &step, &mod) != EOF) {
		long next = 0;
		memset(flag, 0, sizeof(flag));

		long cnt = 0;
		while (!flag[next] && cnt < mod) {
			flag[next] = 1;
			next = (next + step) % mod;
			cnt ++;
		}
		printf("%10ld%10ld    ", step, mod);
		if (cnt == mod) {
			printf("Good Choice\n\n");
		} else {
			printf("Bad Choice\n\n");
		}

	}
	return 0;
}
