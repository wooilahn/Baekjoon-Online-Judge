#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
queue<int> q;

int main() {

	char str[10] = { 0 };
	int N, target, back_n = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &target);
			q.push(target);

			back_n = target;
		}
		else if (!strcmp(str, "pop")) {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (!strcmp(str, "size"))
			printf("%d\n", q.size());
		else if (!strcmp(str, "empty"))
			printf("%d\n", q.empty());
		else if (!strcmp(str, "front")) {
			if (q.empty())
				printf("-1\n");
			else 
				printf("%d\n", q.front());
		}
		else if (!strcmp(str, "back")) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", back_n);
		}
	}

	return 0;
}
