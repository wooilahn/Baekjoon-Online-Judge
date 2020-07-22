#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool check[10] = { 0 };
vector<char> v;
vector<int> max_v;
vector<int> min_v;

int main() {
	char c;
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%c", &c);
		while (c != '<' && c != '>')
			scanf("%c", &c);

		v.push_back(c);
	}

	int max_up = 9;

	if (v.at(0) == '<') {
		max_v.push_back(max_up - 1);
		max_v.push_back(max_up);
	}
	else if (v.at(0) == '>') {
		max_v.push_back(max_up);
		max_v.push_back(max_up - 1);
	}
	max_up -= 2;

	for (int i = 1; i < v.size(); i++) {
		if (v.at(i) == '>')
			max_v.push_back(max_up);
		else if (v.at(i) == '<') {
			max_v.push_back(max_up);

			for (int k = max_v.size() - 1; k >= 1; k--) {
				if (max_v.at(k - 1) > max_v.at(k) && v.at(k - 1) == '<') {
					int tmp = max_v.at(k - 1);
					max_v[k - 1] = max_v[k];
					max_v[k] = tmp;
				}
			}
		}

		max_up -= 1;
	}

	int min_down = 0;

	if (v.at(0) == '<') {
		min_v.push_back(min_down);
		min_v.push_back(min_down + 1);
	}
	else if (v.at(0) == '>') {
		min_v.push_back(min_down + 1);
		min_v.push_back(min_down);
	}
	min_down += 2;

	for (int i = 1; i < v.size(); i++) {
		if (v.at(i) == '<')
			min_v.push_back(min_down);
		else if (v.at(i) == '>') {
			min_v.push_back(min_down);

			for (int k = min_v.size() - 1; k >= 1; k--) {
				if (min_v.at(k - 1) < min_v.at(k) && v.at(k - 1) == '>') {
					int tmp = min_v.at(k - 1);
					min_v[k - 1] = min_v[k];
					min_v[k] = tmp;
				}
			}
		}

		min_down += 1;
	}

	for (int i = 0; i < max_v.size(); i++)
		printf("%d", max_v.at(i));
	printf("\n");
	for (int i = 0; i < min_v.size(); i++)
		printf("%d", min_v.at(i));
	printf("\n");

	return 0;
}
