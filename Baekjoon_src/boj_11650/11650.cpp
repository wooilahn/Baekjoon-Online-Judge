#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;

int main() {

	int N, x, y;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	for (int i = 0;i < N;i++) 
		printf("%d %d\n", v[i].first, v[i].second);
	
	return 0;
}
