#include <cstdio>

#define likely(x) __builtin_expect(!!(x), 1)

#define unlikely(x) __builtin_expect(!!(x), 0)

const int MAXN = 50001;
int num[MAXN];

const int MAXS = 20 * MAXN + 1;
char buf[MAXS];

int analyse(char* buf, int len = MAXS) {
    int i;
    num[i = 0] = 0;
    bool flag = false;
	for (char *p = buf; *p && p - buf < len; ++p) {
		if (*p == ' ' || *p == '\n') {
            if (flag) {
                num[i] = 0 - num[i];
                flag = false;
            }
			num[++i] = 0;
        }
		else if(unlikely(*p == '-')) {
            flag = true;
        }
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

int bufidx = 0;
void double2buf(double val, int size) {
    bufidx += sprintf(buf + bufidx, "%.4f\n", val);
    buf[bufidx] = '\0';
}

void str2buf(const char* str, int len) {
    memcpy(buf + bufidx, str, len);
    bufidx += len;
    buf[bufidx] = '\0';
}

void printall() {
    printf("%s", buf);
}
