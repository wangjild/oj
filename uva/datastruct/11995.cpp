#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

struct opstream {
  int op, num;
};

struct opstream ops[1001];
int n;

const int IS_NOTH = 0;
const int IS_STACK = 1;
const int IS_QUEUE = 2;
const int IS_PRQUE = 4;
const int NOT_SURE = 8;

const int PUSH = 1;
const int POP = 2;

int isStack() {
  stack<int> stk;
  for (int i = 0; i < n; ++i) {
    if (ops[i].op == PUSH) {
      stk.push(ops[i].num);
    } else {
      if (stk.empty() || stk.top() != ops[i].num) {
        return IS_NOTH;
      }
      stk.pop();
    }
  }

  return IS_STACK;
}

int isQueue() {
  queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (ops[i].op == PUSH) {
      que.push(ops[i].num);
    } else {
      if (que.empty() || que.front() != ops[i].num) {
        return IS_NOTH;
      }
      que.pop();
    }
  }

  return IS_QUEUE;
}

int isPriority() {

  priority_queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (ops[i].op == PUSH) {
      que.push(ops[i].num);
    } else {
      if (que.empty() || que.top() != ops[i].num) {
        return IS_NOTH;
      }
      que.pop();
    }
  }

  return IS_PRQUE;
}

int main() {

  while (EOF != scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &ops[i].op, &ops[i].num);
    } 

    int result = isStack() | isQueue() | isPriority();
    switch (result) {
      case IS_STACK:
        printf("stack\n");
        break;
      case IS_QUEUE:
        printf("queue\n");
        break;
      case IS_PRQUE:
        printf("priority queue\n");
        break;
      case IS_NOTH:
        printf("impossible\n");
        break;
      default:
        printf("not sure\n");
    }
  }
  return 0;
}
