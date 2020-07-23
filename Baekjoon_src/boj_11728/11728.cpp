#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
	int N, M, len, tmp;
	scanf("%d %d", &N, &M);
	len = N + M;

	for (int i = 0; i < len; i++) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) 
		printf("%d ", arr.at(i));
	
	printf("\n");
 
	return 0;
}
