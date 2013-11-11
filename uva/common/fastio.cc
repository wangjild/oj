#include <cstdio>

const int MAXN = 10000001;
int num[MAXN];

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
	return i;
}

int fastreadint() {
    int len = fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';

	return analyse(buf, len);
}
