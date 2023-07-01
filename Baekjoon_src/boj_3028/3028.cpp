#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;

	int ball = 1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			if (ball == 1)
				ball = 2;
			else if (ball == 2)
				ball = 1;
		}

		if (s[i] == 'B') {
			if (ball == 2)
				ball = 3;
			else if (ball == 3)
				ball = 2;
		}

		if (s[i] == 'C') {
			if (ball == 1)
				ball = 3;
			else if (ball == 3)
				ball = 1;
		}
	}

	printf("%d\n", ball);

	return 0;
}
