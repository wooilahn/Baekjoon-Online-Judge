#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	int s1h = stoi(s1.substr(0, 2));
	int s1m = stoi(s1.substr(3, 2));
	int s1s = stoi(s1.substr(6, 2));

	int s2h = stoi(s2.substr(0, 2));
	int s2m = stoi(s2.substr(3, 2));
	int s2s = stoi(s2.substr(6, 2));

	if (s1h == s2h && s1m == s2m && s1s == s2s) {
		cout << "24:00:00\n";
		return 0;
	}

	int ah, am, as;

	if (s1s <= s2s)
		as = s2s - s1s;
	else {
		as = (s2s + 60) - s1s;
		s2m--;
	}

	if (s1m <= s2m)
		am = s2m - s1m;
	else {
		am = (s2m + 60) - s1m;
		s2h--;
	}

	if (s1h <= s2h)
		ah = s2h - s1h;
	else 
		ah = (s2h + 24) - s1h;

	string ahs = to_string(ah);
	string ams = to_string(am);
	string ass = to_string(as);

	if (ahs.size() == 1)
		ahs = '0' + ahs;
	if (ams.size() == 1)
		ams = '0' + ams;
	if (ass.size() == 1)
		ass = '0' + ass;

	cout << ahs << ":" << ams << ":" << ass << endl;
	return 0;
}
