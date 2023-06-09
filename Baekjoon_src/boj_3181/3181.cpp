#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	string s, token, ans;
	getline(cin, s);

	ans = "";
	stringstream sstream(s);

	vector<string> v;
	v.push_back("i");
	v.push_back("pa");
	v.push_back("te");
	v.push_back("ni");
	v.push_back("niti");
	v.push_back("a");
	v.push_back("ali");
	v.push_back("nego");
	v.push_back("no");
	v.push_back("ili");

	while (getline(sstream, token, ' ')) {
		bool flag = true;

		if (n) {
			for (int k = 0; k < v.size(); k++) {
				if (v[k] == token) {
					flag = false;
					break;
				}
			}
		}

		if (flag)
			ans += toupper(token[0]);
		n++;
	}

	cout << ans << endl;

	return 0;
}
