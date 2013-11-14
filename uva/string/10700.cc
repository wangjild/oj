#include <cstdio>
#include <stack>
using namespace std;

char buf[64];

inline long long getStackMul(stack<long long> &st, int cur) {
	long long mul = 1;
	while (!st.empty()) {
		mul *= st.top(); st.pop();
	}

	return mul * cur;
}

inline long long getStackAdd(stack<long long> &st, int cur) {
	long long add = 0;
	while (!st.empty()) {
		add += st.top(); st.pop();
	}
	return add + cur;
}

int main () {
    int n;
    scanf("%d\n", &n);

    while (n --) {
		stack<long long> small;
		stack<long long> big;
        gets(buf);
        int cur = 0, sum = 0;
		long long maxval = 1, minval = 0;

        do {
            if (buf[cur] >= '0' && buf[cur] <= '9') {
                sum = sum * 10 + buf[cur] - '0';
				continue;
            } else if (buf[cur] == '+') {
				// mul stack first
				minval += getStackMul(small, sum);
				// push sum to add stack
				big.push(sum); 	
			} else if (buf[cur] == '*'){
				// add stack first
				maxval *= getStackAdd(big, sum);
				// push sum to mul stack
				small.push(sum);
			} else {
				minval += getStackMul(small, sum);
				maxval *= getStackAdd(big, sum);
			}
			sum = 0;
        } while (buf[cur++] != '\0');

		printf("The maximum and minimum are %lld and %lld.\n", maxval, minval);
    }
}
