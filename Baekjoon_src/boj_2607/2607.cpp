#include <iostream>
#include <string>

using namespace std;

int chk[30] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int ans = 0;
	cin >> N;

	N--;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) 
		chk[s[i] - 'A']++;

	while (N--) {
		string s2;
		cin >> s2;
		int chk2[30] = { 0 };

		for (int i = 0; i < s2.size(); i++) 
			chk2[s2[i] - 'A']++;
		
		int diff = 0;

		for (int i = 0; i < 30; i++) {
			diff += abs(chk[i] - chk2[i]);
		}

		if (diff <= 1)
			ans++;
		else if (s.size() == s2.size() && diff == 2)
			ans++;
	}

	cout << ans << "\n";
	return 0;
}
