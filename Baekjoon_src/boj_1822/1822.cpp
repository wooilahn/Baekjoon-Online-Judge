#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq1;
priority_queue<int> pq2;
vector<int> v;

int main() {
	int na, nb;
	int a, b;

	scanf("%d %d", &na, &nb);

	for (int i = 0; i < na; i++) {
		scanf("%d", &a);
		pq1.push(-a);
	}

	for (int i = 0; i < nb; i++) {
		scanf("%d", &b);
		pq2.push(-b);
	}

	int t1, t2;
	t2 = -pq2.top();
	pq2.pop();

	while (!pq1.empty()) {
		int t1 = -pq1.top();
		pq1.pop();

		if (t1 == t2 && t2 != -1) {
			if (pq2.empty()) {
				t2 = -1;
			}
			else {
				t2 = -pq2.top();
				pq2.pop();
			}
			continue;
		}

		if (t1 < t2) {
			v.push_back(t1);
		}
		else if(t1 > t2) {
			while (t1 > t2) {
				if (pq2.empty()) {
					t2 = -1;
					break;
				}
				else {
					t2 = -pq2.top();
					pq2.pop();
				}
			}

			if (t2 == -1 || t1 < t2)
				v.push_back(t1);
		}
	}

	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;

}
