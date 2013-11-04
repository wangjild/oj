#include<cstdio>
#include<cmath>

int solve(int k) {
  double M = pow(2, k), sum = 0;
  for(int i = 1; ; i++) {
    sum += log(i);
    if(sum > M * log(2)) return i-1;
  }
}

int main() {
  int y;
  while(scanf("%d", &y) == 1 && y) printf("%d\n", solve(y/10 - 194));
  return 0;
}
