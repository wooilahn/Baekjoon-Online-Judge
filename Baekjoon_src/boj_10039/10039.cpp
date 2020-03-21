#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> v;

int main() {

	int tmp, sum = 0;

	for (int i = 0;i < 5;i++) {
		scanf("%d", &tmp);
		
		if (tmp < 40)
			tmp = 40;

		sum += tmp;
	}

	printf("%d\n", sum / 5);
	return 0;
}
