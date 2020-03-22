#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		int tmp;
		scanf("%d", &tmp);

		v.push_back(tmp);
	}

	printf("%d %d\n",  *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));

	return 0;
}
