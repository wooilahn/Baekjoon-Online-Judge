#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main() {
	int a, b, num;
	int ans = 0;

	scanf("%d %d", &a, &b);

	for (int i = 0; i < a+b; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	v.push_back(-1);

	for (int i = 0; i < a+b; i++) {
		if (v[i] == v[i+1]) 
			ans--;
		else
			ans++;
	}

	printf("%d\n", ans);
	return 0;
}

