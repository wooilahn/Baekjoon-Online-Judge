#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	v.push_back(A);
	v.push_back(B);
	v.push_back(C);

	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++)
		printf("%d ", v.at(i));
	printf("\n");

	return 0;
}
