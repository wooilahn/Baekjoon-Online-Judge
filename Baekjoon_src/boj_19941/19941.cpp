#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
bool check[20005] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	string s;
	cin >> s;

	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') {
			for (int tt = i - K; tt <= i + K; tt++) {
				if (tt < 0 || tt > N)
					continue;

				if (s[tt] == 'H' && check[tt] == false) {
					ans++;
					check[tt] = true;
					break;
				}
			}
		}
	} 

	cout << ans << "\n";
	return 0;
}
