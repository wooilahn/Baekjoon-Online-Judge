#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

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

	sort(v.begin(), v.end());

	for (int i = 0;i < N;i++)
		printf("%d\n", v.at(i));

	return 0;
}
