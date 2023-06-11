#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v1;
vector<string> v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	string s1, s2;
	bool flag = true;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s1;
		v1.push_back(s1);
	}

	for (int i = 0; i < N; i++) {
		cin >> s2;
		v2.push_back(s2);
	}

	for (int i = 0; i < s1.size(); i++) {
		for (int k = 0; k < N; k++) {
			if (v2[k][i*2] != v1[k][i] || v2[k][i*2+1] != v1[k][i]) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}

	if (flag)
		cout << "Eyfa\n";
	else
		cout << "Not Eyfa\n";

	return 0;
}
