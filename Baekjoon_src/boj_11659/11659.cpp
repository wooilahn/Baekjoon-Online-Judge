#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int arr[100005] = { 0 };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);

		arr[i + 1] = arr[i] + num;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}

	return 0;
}
