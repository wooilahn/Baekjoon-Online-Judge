#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, tmp;
vector<int> v;

bool binary_search(int target) {

	bool ans = false;
	int s = 0, e = N-1, mid = (s + e) / 2;

	while (s <= e) {

		mid = (s + e) / 2;

		if (v[mid] == target) {
			ans = true;
			break;
		}
		else {
			if (v[mid] > target)
				e = mid - 1;
			else if (v[mid] < target)
				s = mid + 1;
		}
	}
	return ans;
}

int main() {

	
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	scanf("%d", &M);

	for (int i = 0;i < M;i++) {
		scanf("%d", &tmp);
		printf("%d\n", binary_search(tmp));
	}

	return 0;
}
