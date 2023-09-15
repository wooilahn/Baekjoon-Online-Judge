#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int multiTap[105] = { 0 };
int electricDevice[105] = { 0 };
bool check[105] = { 0 };

vector<int> schedule;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++) {
		int num;
		scanf("%d", &num);
		schedule.push_back(num);
	}

	int ans = 0;

	for (int i = 0; i < K; i++) {
		int nowSchedule = schedule[i];
		bool plugIn = false;

		for (int t = 0; t < N; t++) {
			if (multiTap[t] == nowSchedule) {
				plugIn = true;
				break;
			}
		}

		if (plugIn)
			continue;

		for (int t = 0; t < N; t++) {
			if (multiTap[t] == 0) {
				multiTap[t] = nowSchedule;
				plugIn = true;
				break;
			}
		}

		if (plugIn)
			continue;

		int idx, deviceIdx = -1;

		for (int t = 0; t < N; t++) {
			int lastIdx = 0;

			for (int k = i + 1; k < K; k++) {
				if (multiTap[t] == schedule[k])
					break;
				lastIdx++;
			}

			if (lastIdx > deviceIdx) {
				idx = t;
				deviceIdx = lastIdx;
			}
		}

		multiTap[idx] = schedule[i];
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
