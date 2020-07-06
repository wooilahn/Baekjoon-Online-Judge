#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

int check[10000] = { 0 };
using namespace std;

int main() {
	vector<double> v;
	vector<int> v2;

	int n;
	double num, sum = 0.0;

	scanf("%d", &n);

	while (n--) {
		scanf("%lf", &num);
		v.push_back(num);
		sum += num;
		check[((int)num + 4000)]++;
	}

	sort(v.begin(), v.end());

	double  n1, n2, n3, n4;
	int res = 1, val = -1;
	bool flag = false;

	for (int i = 0; i < 8005; i++) {
		if (res < check[i]) {
			res = check[i];
			v2.clear();
			v2.push_back(i - 4000);
		}
		else if (res == check[i]) {
			res = check[i];
			v2.push_back(i - 4000);
		}
	}

	if (v2.size() >= 2) {
		sort(v2.begin(), v2.end());
		n3 = (double)v2.at(1);
	}
	else
		n3 = (double)v2.at(0);


	n1 = (sum / v.size());
	n2 = v.at(v.size() / 2);
	n4 = v.at(v.size() - 1) - v.at(0);

	if (n1 > -0.5 && n1 < 0)
		n1 = -n1;

	printf("%.0lf\n%.0lf\n%.0lf\n%.0lf", n1, n2, n3, n4);

	return 0;
}
