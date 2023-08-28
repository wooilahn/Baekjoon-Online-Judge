#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1;
vector<int> v2;


int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int c1, c2;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &c1, &c2);
		
		v1.push_back(c1);
		v2.push_back(c2);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int p_cost = (N / 6) * v1[0];

	if (N % 6 != 0)
		p_cost += v1[0];

	int c_cost = ((N/6)*v1[0]) + ((N % 6)*v2[0]);
	int a_cost = N * v2[0];

	printf("%d\n", min(p_cost, min(c_cost, a_cost)));

	return 0;
}
