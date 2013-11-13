#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 10000001;
int num[MAXN];
int numlen = 0;
const int MAXS = 12 * MAXN + 1;
char buf[MAXS];

int analyse(char* buf, int len = MAXS) {
    int i;
    num[i = 0] = 0;
	for (char *p = buf; *p && p - buf < len; ++p) {
		if (*p == ' ' || *p == '\n')
			num[++i] = 0;
		else 
			num[i] = num[i] * 10 + *p - '0';
	}
	return numlen = i;
}

int fastreadint() {
    int len = fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';

	return analyse(buf, len);
}

void dump_buf() {
	printf("*****DUMP BUF*****\n");
	printf("%s", buf);
	printf("*******DONE*******\n");
}

void dump_num() {
	printf("*****DUMP NUM*****\n");
	printf("num:%d\n", numlen);
	for (int i = 0; i < numlen; ++i) {
		printf("%d ", num[i]);
		if (i && i%2 == 0)
			printf("\n");
	}
	printf("\n");
	printf("*******DONE*******\n");
}

/********** lib done ************/
#define MAXNUM 500010

int n, flag;
int loc[MAXNUM] , res[MAXNUM];

int solve(){
    sort(loc , loc+n);
    sort(res , res+n);
    
	return memcmp(loc, res, sizeof(int) * n);
}

int main() {
	int total = fastreadint();
	//dump_buf(); dump_num();
	for(int s = 0; num[s] != 0; s += 2*num[s] + 1) {
		n = num[s];
		if (n % 2) {
			printf("NO\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			loc[i] = num[s + 2*i + 1];
			res[i] = num[s + 2*i + 2];
		}
        if(solve() == 0) printf("YES\n");
        else printf("NO\n");
	}
    return 0;
}
