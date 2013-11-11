#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 51;

struct mystring {
	char str[N];
	int len;
};

mystring str[N];

void find_cmp_point(const mystring& a, char** ap, 
		const mystring& b, char** bp) {
	int alen = strlen(*ap), blen = strlen(*bp);
	if (alen > blen) {
		while (strncmp(*ap, *bp, blen) == 0) {
			*ap += blen;
		}
	} else {
		while (strncmp(*ap, *bp, blen) == 0) {
			*bp += len;
		}
	}

	find_cmp_point(a, ap, b, bp);
}

bool compare(const mystring& a, const mystring& b) {
	char* ap = a.str, bp = b.str;
	find_cmp_point(a, &ap, b, &bp);

	int len = min (strlen(ap), strlen(bp));

	for (int i = 0; i < len; ++i) {
		if ( *(ap+i) != *(bp + i))
			return *(ap+i) > *(bp + i);
	}
	return true;
}

int main () {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) {
			//int num; scanf("%d", &num);
			//sprintf(str[i].str, "%d", num);
			scanf("%s", str[i].str);
			str[i].len = strlen(str[i].str);
		}

		sort(str, str + n, compare);

		for (int i = 0; i < n; ++i) {
			printf("%s", str[i].str);
		}
		printf("\n");
	}
	return 0;
}
