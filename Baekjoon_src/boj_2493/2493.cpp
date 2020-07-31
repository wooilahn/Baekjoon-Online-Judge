#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
stack<int> idx;
vector<int> ans;

int main() {
	int N, tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		if (s.empty()) {
			s.push(tmp);
			idx.push(i);
			ans.push_back(0);
		}
		else {
			if (s.top() >= tmp) {
				s.push(tmp);
				ans.push_back(idx.top() + 1);
				idx.push(i);
			}
			else if (s.top() < tmp) {
				while (true) {
					if (s.empty()) {
						s.push(tmp);
						idx.push(i);
						ans.push_back(0);
						break;
					}
					else if (!s.empty()) {
						if (s.top() < tmp) {
							s.pop();
							idx.pop();
						}
						else if (s.top() >= tmp) {
							s.push(tmp);
							ans.push_back(idx.top() + 1);
							idx.push(i);
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans.at(i));
	printf("\n");

	return 0;
}
