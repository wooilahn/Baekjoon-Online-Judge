#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int arr[100005] = { 0 };

int main() {
	int N, M;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);

		if (i == 0)
			arr[1] = num;
		else
			arr[i+1] = arr[i] + num;
	}

	scanf("%d", &M);
	int i, j;

	for (int k = 0; k < M; k++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", arr[j] - arr[i-1]);
	}

	return 0;
}
