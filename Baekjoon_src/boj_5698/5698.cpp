#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);

		if (s.size() == 1 && s[0] == '*')
			break;

		
		char t_s = toupper(s[0]);
		bool t_flag = true;

		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == ' ') {
				if (toupper(s[i+1]) != toupper(t_s)) {
					t_flag = false;
				}
			}
		}

		if (t_flag)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}
