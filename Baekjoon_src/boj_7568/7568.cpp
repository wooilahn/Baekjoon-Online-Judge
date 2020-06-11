#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int ans[55] = { 0 };
vector<pair<int, int>> v;

int main() {

	int n, w, h, cnt;
	scanf("%d", &n);

	int t_w, t_h;
	int k_w, k_h;

	for (int i = 0;i < n;i++) {
		scanf("%d %d", &w, &h);
		v.push_back(make_pair(w, h));
	}

	for (int i = 0;i < n;i++) {
		t_w = v.at(i).first;
		t_h = v.at(i).second;
		cnt = 1;

		for (int k = 0;k < n;k++) {
			if (i == k)
				continue;
			else {
				k_w = v.at(k).first;
				k_h = v.at(k).second;

				if (t_w < k_w && t_h < k_h)
					cnt++;
			}
		}

		ans[i] = cnt;
	}

	for (int i = 0;i < n;i++) 
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
