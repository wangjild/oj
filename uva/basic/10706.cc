#include <cstdio>

#define MAX 1000000000
//          2147483647

int n[11] = {
	0,
	0,
	9,
	108,
	1107,
	11106,
	111105,
	1111104,
	11111103,
	111111102,
	1111111101,
};

int div[11] = {
	1,
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,	
	1000000000,
};

long long len(long long x) {

	for (int i = 10; i > 0; --i) {
		if (x / div[i]) {
			// printf("i:%d\n", i);
			return i * x - n[i];	
		} 
	}
	return 0;
}

const int lenmax = 30937;
long long numlen[lenmax] = {0};
long long justlen[lenmax] = {0};
void init() {
	for (int i = 1; i < lenmax; ++i)
		justlen[i] = len(i);
	for (int i = 1; i < lenmax; ++i) {
		numlen[i] = numlen[i - 1] + justlen[i];
	}
}

long long bsearch(long long x, long long left, long long right, long long *p) {
	long long mid = (left + right) / 2;
	if ( x > p[mid - 1] && x <= p[mid])
		return mid;
	if (x > p[mid])
		return bsearch(x, mid + 1, right, p);
	else {
		return bsearch(x, left, mid - 1, p);
	}
}

int main() {

	init();
	int c;
	scanf("%d", &c);
	while (c--) {
		long long num;
		scanf("%lld", &num);

		// 123...idx
		long long idx = bsearch(num, 1, lenmax - 1, numlen);
//		printf("idx:%lld startidx:%lld\n", idx, num - numlen[idx - 1]);
//		printf("lenof[112123--123idx]:%lld, lenof[1234--idx]:%lld\n", numlen[idx], justlen[idx]);
		long long numberlen = num - numlen[idx - 1];

		// number 是 123...idx 所指向的数字
		long long number = bsearch(numberlen, 1, lenmax - 1, justlen);
		long long last = numberlen - justlen[number - 1];
//		printf("number:%lld last:%lld\n", number, last);

		char buf[16];
		sprintf(buf, "%lld", number);
		printf("%c\n", buf[last - 1]);
	}
}
