#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, pair<int, string>>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		int slen = s.size();
		int ssum = 0;

		for (int k = 0; k < s.size(); k++) {
			if (s[k] >= '0' && s[k] <= '9')
				ssum += s[k] - '0';
		}

		v.push_back(make_pair(slen, make_pair(ssum, s)));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].second.second << endl;

	return 0;
}
