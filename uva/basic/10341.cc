#include <cstdio>
#include <cmath>
#include <cstring>

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

/********* Logic Start**********/
int p, q, r, s, t, u;

inline double formula(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

inline double formula2(double x) {
    return -p * exp(-x) + q * cos(x) - r * sin(x) + s / (cos(x) * cos(x)) + 2 * t * x;
}

int main() {
    int n = fastreadint();

    for (int i = 0; i < n;) {
        p = num[i++], q = num[i++], r = num[i++], s = num[i++], t = num[i++], u = num[i++];
        //printf("p:%d q:%d r:%d s:%d t:%d u:%d\n", p, q, r, s, t, u);
        double x1 = formula(0.0), x2 = formula(1.0);
        if (unlikely(x1 == 0)) {
            double2buf(0.0000, 4); 
            continue;
        } else if (unlikely(x2 == 1.0)) {
            double2buf(1.0000, 4); 
            continue;
        }

        if (x1 * x2 > 0) {
            str2buf("No solution\n", 12);
            continue;
        }

        double x = 0.5, tmp = 0.0;
        while (likely(fabs(x - tmp) > 1e-3)) {
            tmp = x;
            x -= formula(x)/formula2(x);
        }
        //printf("x:%f\n", x);
        double2buf(x, 4);
    }

    printall();
}
