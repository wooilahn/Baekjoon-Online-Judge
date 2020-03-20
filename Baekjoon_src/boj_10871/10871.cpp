#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main() {

	int N, X;
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp < X)
			v.push_back(tmp);
	}

	for (int i = 0; i < v.size(); i++)
		printf("%d ", v.at(i));

	return 0;
}
