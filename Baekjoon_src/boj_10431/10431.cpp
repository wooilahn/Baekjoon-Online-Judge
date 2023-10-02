#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int P, T;
	scanf("%d", &P);

	while (P--) {
		scanf("%d", &T);

		vector<int> v;

		for (int i = 0; i < 20; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		int ans = 0;

		for (int i = 1; i < 20; i++) {
			for (int j = i; j >= 1; j--) {
				if (v[j] < v[j-1]) {
					ans++;
					int tmp = v[j];
					v[j] = v[j - 1];
					v[j - 1] = tmp;
				}
			}
		}

		printf("%d %d\n", T, ans);
	}

	return 0;
}
