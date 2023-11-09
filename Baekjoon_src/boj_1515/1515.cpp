#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[15] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	string s;
	cin >> s;
	int idx = 0;

	for (int i = 1;;i++) {
		string ss = to_string(i);

		for (int k = 0; k < ss.size(); k++) {
			if (ss[k] == s[idx]) {
				idx++;
			}

			if (idx >= s.size())
				break;
		}

		if (idx == s.size()) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
