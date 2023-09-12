#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<char> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	string s;

	cin >> N >> K;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		while (!d.empty() && K != 0 && d.back() < s[i]) {
			d.pop_back();
			K--;
		}

		d.push_back(s[i]);
	}

	for (int i = 0; i < d.size()-K; i++)
		cout << d[i];
	cout << "\n";

	return 0;
}
