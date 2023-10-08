#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while (true) {
		cin >> s;

		if (s == "end")
			break;

		bool flag = true;

		int mCnt = 0;

		int tCnt1 = 0;
		int tCnt2 = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				mCnt++; // 1. 모음 한 개 이상 포함 여부 확인

				tCnt1++;
				tCnt2 = 0;
			}
			else {
				tCnt1 = 0;
				tCnt2++;
			}

			if (tCnt1 >= 3 || tCnt2 >= 3)
				flag = false;

			if (i > 0) { // 3. 같은 글자 연속 두번 여부 확인 (e와 o 제외)
				if (s[i-1] == s[i]) {
					if (s[i] != 'e' && s[i] != 'o')
						flag = false;
				}
			}
		}

		if (mCnt == 0)
			flag = false;

		if (flag) 
			cout << "<" << s << "> is acceptable.\n";
		else
			cout << "<" << s << "> is not acceptable.\n";
	}

	return 0;
}
