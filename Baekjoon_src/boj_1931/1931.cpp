#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct time {
	int begin_t;
	int end_t;
}Time;

bool cmp(Time t1, Time t2) {

	if (t1.end_t == t2.end_t)
		return t1.begin_t < t2.begin_t;
	else
		return t1.end_t < t2.end_t;
}

int main() {

	int N, cur = 0, ans = 0;
	scanf("%d", &N);

	vector<Time> v;

	for (int i = 0; i < N; i++) {
		int bt, et;
		scanf("%d %d", &bt, &et);

		Time T;
		T.begin_t = bt;
		T.end_t = et;

		v.push_back(T);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		if (cur <= v[i].begin_t) {
			cur = v[i].end_t;
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
