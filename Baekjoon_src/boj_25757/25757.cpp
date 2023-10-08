#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	char gt;
	vector<string> v;

	cin >> N >> gt;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (gt == 'Y')
		cout << v.size() << "\n";
	else if (gt == 'F')
		cout << v.size() / 2 << "\n";
	else if (gt == 'O')
		cout << v.size() / 3 << "\n";
	
	return 0;
}
