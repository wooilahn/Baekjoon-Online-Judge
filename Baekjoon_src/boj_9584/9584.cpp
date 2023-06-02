#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	string target;
	int n;

	cin >> target;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int k = 0; k < s.size(); k++) {
			if (target[k] != '*') {
				if (target[k] != s[k])
					break;
			}

			if (k == s.size() - 1)
				v.push_back(s);
		}
	}

	cout << v.size() << "\n";
	for (int k = 0; k < v.size(); k++)
		cout << v[k] << endl;

	return 0;
}
