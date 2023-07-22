#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	for (int i = 1; i <= M; i++) {
		for (int k = 0; k < N-1; k++) {
			int a = v[k] % i;
			int b = v[k+1] % i;

			if (a > b) {
				int tmp = v[k];
				v[k] = v[k + 1];
				v[k + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", v[i]);

	return 0;
}
