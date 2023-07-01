#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<string, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		int cur = i;
		int c;
		string s = "";

		while (cur) {
			c = cur % 10;
			cur /= 10;

			switch (c) {
			case 0:
				s = "zero" + s;
				break;
			case 1:
				s = "one" + s;
				break;
			case 2:
				s = "two" + s;
				break;
			case 3:
				s = "three" + s;
				break;
			case 4:
				s = "four" + s;
				break;
			case 5:
				s = "five" + s;
				break;
			case 6:
				s = "six" + s;
				break;
			case 7:
				s = "seven" + s;
				break;
			case 8:
				s = "eight" + s;
				break;
			case 9:
				s = "nine" + s;
				break;
			}
		}

		v.push_back(make_pair(s, i));
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " ";

		cnt++;
		if(cnt == 10){
			cout << "\n";
;			cnt = 0;
		}
	}

	return 0;
}
