#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	string s;

	while (getline(cin, s)) {
		bool sFlag = false;
		string sN = "";
		string sM = "";
			
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' || s[i] == '\n') {
				sFlag = true;
				continue;
			}

			if (!sFlag)
				sN += s[i];
			else
				sM += s[i];
		}

		N = stoi(sN);
		M = stoi(sM);
		int ans = 0;

		for (int i = N; i <= M; i++) {
			int nCnt[10] = { 0 };
			int nFlag = false;
			string ss = to_string(i);

			for (int k = 0; k < ss.size(); k++) {
				if (nCnt[ss[k] - '0']) {
					nFlag = true;
					break;
				}
				nCnt[ss[k] - '0']++;
			}

			if (!nFlag)
				ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}
