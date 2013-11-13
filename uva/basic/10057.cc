#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define likely(x) __builtin_expect(!!(x), 1)

#define unlikely(x) __builtin_expect(!!(x), 0)

const int MAXN = 1000010;
int num[MAXN];

const int MAXS = 10 * MAXN + 1;
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

void dumpnum(int n) {
    printf("*****DUMP STAR*****\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
        if (i && i % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n*****DUMP DOWN****\n");
}

int main() {
    int n = fastreadint();
    //dumpnum(n);
    int i = 0;

    char otbuf[64];
    int mid, left, right, leftmark, rightmark;
    while (i < n) {
        left = i + 1, right = left + num[i];
        sort(num + left, num + right);
        
        int n1 = 0, n2 = 0;
        mid = (num[i] - 1) / 2;
        if (num[i] % 2) {
            n2 = 1;
            leftmark = rightmark = num[left + mid];
        } else {
            n2 = num[mid + 1 + left] - num[mid + left] + 1;
            leftmark = num[left + mid];
            rightmark = num[left + mid + 1];
        }
        for(int k = mid; num[left+k] == leftmark && k >= 0; --k) {
            n1 ++;
        }
        for (int k = mid + 1; num[left+k] == rightmark && k < num[i]; ++k){
            n1 ++;
        }
        // sprintf(otbuf, "%d %d %d\n", num[left + mid], n1, n2);
        // str2buf(otbuf, strlen(otbuf));
        bufidx += sprintf(buf + bufidx, "%d %d %d\n", num[left + mid], n1, n2);
        buf[bufidx] = '\0';
        i += 1 + num[i];
    }

    printall();
    return 0;
}
