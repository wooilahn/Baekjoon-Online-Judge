#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int row, col, num;
int cache[1009][1009];

vector<pair<int, int>> pathA;
vector<pair<int, int>> pathB;
vector<int> v;

int getMaxDistance(int A, int B) {

	if (A == num || B == num)
		return 0;

	int& ret = cache[A][B];

	if (ret != -1)
		return ret;

	ret = 987654321;

	// 다음 위치
	int maxLocation = max(A, B) + 1;

	// A, B 경찰차가 움직일 때의 이동거리
	int distA = abs(pathA[maxLocation].first - pathA[A].first) + abs(pathA[maxLocation].second - pathA[A].second);
	int distB = abs(pathB[maxLocation].first - pathB[B].first) + abs(pathB[maxLocation].second - pathB[B].second);

	int ret1 = getMaxDistance(maxLocation, B) + distA;
	int ret2 = getMaxDistance(A, maxLocation) + distB;

	return ret = min(ret1, ret2);
}

void reconstruct(int A, int B) {
	if (A == num || B == num)
		return;

	int maxLocation = max(A, B) + 1;

	// A, B 경찰차가 움직일 때의 이동거리
	int distA = abs(pathA[maxLocation].first - pathA[A].first) + abs(pathA[maxLocation].second - pathA[A].second);
	int distB = abs(pathB[maxLocation].first - pathB[B].first) + abs(pathB[maxLocation].second - pathB[B].second);

	int ret1 = getMaxDistance(maxLocation, B) + distA;
	int ret2 = getMaxDistance(A, maxLocation) + distB;

	if (ret1 > ret2) {
		printf("2\n");
		reconstruct(A, maxLocation);
	}
	else {
		printf("1\n");
		reconstruct(maxLocation, B);
	}

	return;
}

void solve() {
	printf("%d\n", getMaxDistance(0, 0));
	reconstruct(0, 0);
}

int main() {
	scanf("%d\n%d", &row, &num);
	col = row;
	
	memset(cache, -1, sizeof(cache));

	// first police car coordinate
	pathA.push_back({ 1, 1 });
	pathB.push_back({ row, row });

	for (int i = 0;i < num;i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		pathA.push_back({ x,y });
		pathB.push_back({ x,y });
	}

	solve();
	return 0;
}
