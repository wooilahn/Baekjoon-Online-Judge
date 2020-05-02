#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {

	char num[12] = { 0 };
	scanf("%s", num);

	for (int i = 0;i < strlen(num);i++) 
		v.push_back(num[i] - '0');
	
	sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--)
		printf("%d", v.at(i));

	printf("\n");

	return 0;
}
