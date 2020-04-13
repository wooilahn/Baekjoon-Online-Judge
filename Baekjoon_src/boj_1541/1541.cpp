#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[52] = { 0 };
vector<int> v;

int main() {
	
	scanf("%s", str);
	int sum = 0, tmp = 0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '+') {
			sum += tmp;
			tmp = 0;
		}
		else if (str[i] == '-') {
			sum += tmp;
			v.push_back(sum);
			sum = 0;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += str[i] - '0';
		}
	}

	sum += tmp;
	v.push_back(sum);

	int ans = v.at(0);

	for (int i = 1; i < v.size(); i++) 
		ans -= v.at(i);
	
	
	printf("%d\n", ans);

	return 0;
}
