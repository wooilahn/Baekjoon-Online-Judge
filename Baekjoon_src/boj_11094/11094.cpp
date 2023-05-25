#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	string s;

	cin >> n;
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		getline(cin, s);

		if (s.substr(0, 10) == "Simon says")
			cout << s.substr(10, s.size()) << endl;
	}

	return 0;
}
