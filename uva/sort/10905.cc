#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 51;

struct mystring {
	char str[2*N];
//	int len;
};

mystring str[N];

#define SwapPoint(s, l, sl, ll, flag) { \
	if ((sl) > (ll)) { \
		swap((s), (l)); swap((sl), (ll)); (flag) = !(flag); \
	} \
}

bool compare(const mystring& a, const mystring& b) {
	bool flag = true;
	const char* s = a.str, *l = b.str;
	int sl = strlen(s), ll = strlen(l);
	SwapPoint(s, l, sl, ll, flag);
	while (sl > 0 && memcmp(l, s, sl) == 0) {
//		printf("long :%s len:%d\nshort:%s len:%d\n", l, ll, s, sl);
		l += sl;
		ll -= sl;
		SwapPoint(s, l, sl, ll, flag);
	}

	for (int i = 0; i < sl; ++i) {
		if (*(s + i) != *(l + i)) {
			return flag ? *(s + i) > *(l + i) : !(*(s + i) > *(l + i));
		}
	}

	return flag ? true : false;
}

int main () {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) {
			//int num; scanf("%d", &num);
			//sprintf(str[i].str, "%d", num);
			scanf("%s", str[i].str);
//			str[i].len = strlen(str[i].str);
		}

		sort(str, str + n, compare);

		for (int i = 0; i < n; ++i) {
			printf("%s", str[i].str);
		}
		printf("\n");
	}
	return 0;
}
