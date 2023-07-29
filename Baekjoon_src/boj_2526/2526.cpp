#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int arr[1000005] = { 0 };

int main() {
	int N, P;
	scanf("%d %d", &N, &P);
	arr[N] = 1;

	int pos = (N * N) % P;

	while (true) {
		arr[pos]++;
		
		if (arr[pos] == 2)
			break;

		pos = (pos * N) % P;
	}

	int ans = 1;
	pos = (pos * N) % P;

	while (true) {
		if (arr[pos] == 2)
			break;

		ans++;
		pos = (pos * N) % P;
	}

	printf("%d\n", ans);
	return 0;
}
