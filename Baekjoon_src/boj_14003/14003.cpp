#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int lis[1000005] = { 0 };
int arr[1000005] = { 0 };
pii pls[1000005];

stack<int> s;

int _lower_bound(int start, int end, int target) {

	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (lis[mid] < target) {
			start = mid + 1;
		}
		else
			end = mid;
	}

	return end + 1;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);

	int pLen = 0, pArr = 0;

	lis[pLen] = arr[pArr];
	pls[0].first  = 0;         // order
	pls[0].second = arr[pArr]; // value
	pArr++;

	while (pArr < N) {
		if (lis[pLen] < arr[pArr]) {
			lis[pLen + 1] = arr[pArr];
			pLen++;

			pls[pArr].first  = pLen;
			pls[pArr].second = arr[pArr];
		}
		else {
			int pos = _lower_bound(0, pLen, arr[pArr]);
			lis[pos - 1] = arr[pArr];

			pls[pArr].first  = pos - 1;
			pls[pArr].second = arr[pArr];
		}

		pArr++;
	}

	printf("%d\n", pLen + 1);

	int t = pLen;

	for (int i = N-1; i >= 0; i--) {
		if (t == pls[i].first) {
			s.push(pls[i].second);
			t--;
		}
	}

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");

	return 0;
}
