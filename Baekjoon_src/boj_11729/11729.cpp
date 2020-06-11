#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int n;
int a = 0;
long long cnt = 0;
int arr[1100000][2] = { 0 };

void hanoi(int num, int src, int mid, int des) {
	if (num == 1) {
		arr[a][0] = src; arr[a][1] = des;
		a++; cnt++;
		return;
	}

	hanoi(num - 1, src, des, mid);
	arr[a][0] = src; arr[a][1] = des;
	a++; cnt++;
	hanoi(num - 1, mid, src, des);
}

int main() {
	scanf("%d", &n);

	hanoi(n, 1, 2, 3);
	printf("%lld\n", cnt);
	for (int i = 0; i < a; i++) {
		printf("%d %d\n",arr[i][0], arr[i][1]);
	}
	return 0;
}
