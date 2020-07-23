#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> v;

int main() {

	int N, tmp, target, cnt = 0;
	scanf("%d", &N);

	for (int i = 0; i < N;i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	scanf("%d", &target);

	for (int i = 0;i < N;i++) {
		if (v.at(i) == target)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}

