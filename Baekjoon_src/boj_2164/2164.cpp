#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>

using namespace std;
deque<int> dq;

int main() {

	int N, tmp = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (true) {
		if (dq.size() == 1)
			break;

		dq.pop_front();
		tmp = dq.front();
		dq.pop_front();

		dq.push_back(tmp);
	}

	printf("%d\n", dq.at(0));

	return 0;
}
