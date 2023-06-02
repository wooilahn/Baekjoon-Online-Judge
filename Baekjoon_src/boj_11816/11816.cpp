#include <iostream>
#include <string.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int ans = 0;
	int m = 1;

	if (s[0] == '0') {
		if (s[1] == 'x') { // 16진수
			for (int k = s.size() - 1; k > 1; k--) {
				if(s[k] >= '0' && s[k] <= '9')
					ans += m * (s[k] - '0');
				else if (s[k] >= 'a' && s[k] <= 'f') {
					ans += m * (s[k] - 'a' + 10);
				}

				m *= 16;
			}
		}
		else { // 8진수
			for (int k = s.size() - 1; k > 0; k--) {
				ans += m * (s[k] - '0');
				m *= 8;
			}
		}
		
		cout << ans << "\n";
	}
	else { // 10진수
		cout << s << "\n";
	}

	return 0;
}
