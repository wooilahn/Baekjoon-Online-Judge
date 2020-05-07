#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, M;

int binary_search(int target);

int main() {
	int tmp;
	scanf("%d", &N);
	
	for (int i = 0;i < N;i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	scanf("%d", &M);

	for (int i = 0;i < M;i++) {
		scanf("%d", &tmp);
		printf("%d ", binary_search(tmp));
	}
	printf("\n");
	
	return 0;
}

int binary_search(int target) {
	
	int s_s = 0, s_e = N - 1, s_mid = (s_s + s_e) / 2;

	while (s_s <= s_e) {
		s_mid = (s_s + s_e) / 2;

		if (v[s_mid] == target) {
			if (s_mid == 0) {
				break;
			}

			if (v[s_mid - 1] != target) {
				break;
			}
			else {
				s_e = s_mid - 1;
			}
		}
		else {
			if (v[s_mid] > target) {
				s_e = s_mid - 1;
			}
			else if (v[s_mid] < target) 
				s_s = s_mid + 1;
		}
	}

	int e_s = 0, e_e = N - 1, e_mid = (e_s + e_e) / 2;

	while (e_s <= e_e) {
		e_mid = (e_s + e_e) / 2;

		if (v[e_mid] == target) {
			if (e_mid == N - 1) {
				break;
			}

			if (v[e_mid + 1] != target) {
				break;
			}
			else {
				e_s = e_mid + 1;
			}
		}
		else {
			if (v[e_mid] > target) {
				e_e = e_mid - 1;
			}
			else if (v[e_mid] < target)
				e_s = e_mid + 1;
		}
	}

	if (v[s_mid] != target || v[e_mid] != target)
		return 0;
	else
		return (e_mid - s_mid + 1);
}
