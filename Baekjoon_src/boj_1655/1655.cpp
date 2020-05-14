#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {

	int N, val;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &val);

		if (max_heap.empty())
			max_heap.push(val);
		else if (max_heap.size() == min_heap.size()) 
			max_heap.push(val);
		else 
			min_heap.push(val);
		
		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() >= min_heap.top()) {
			int tmp1 = max_heap.top();
			int tmp2 = min_heap.top();

			max_heap.pop();
			min_heap.pop();
			max_heap.push(tmp2);
			min_heap.push(tmp1);
		}

		printf("%d\n", max_heap.top());
	}

	return 0;
}
