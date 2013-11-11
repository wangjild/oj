#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Job {
	int b, j;
	bool operator < (const Job& x) const {
		return this->j > x.j;
	}
};

int main() {
	int n, c = 1;
	while (scanf("%d", &n), n) {
		vector<Job> v;
		for (int i = 0; i < n; ++i) {
			Job job;
			scanf("%d%d", &job.b, &job.j);
			v.push_back(job);
		}

		sort(v.begin(), v.end());
		int s = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			s += v[i].b;
			ans = max(ans, s+v[i].j);
		}

		printf("Case %d: %d\n", c++, ans);
	}
}
