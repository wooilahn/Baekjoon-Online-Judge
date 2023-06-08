#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> v1;
vector<string> v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v1.push_back(s);
		v2.push_back(s);
	}

	sort(v2.begin(), v2.end());

	bool i_flag = false;
	bool d_flag = false;

	int icnt = 0;
	int dcnt = 0;

	for (int i = 0; i < N; i++) {
		if (v2[N-1-i] == v1[i])
			dcnt++;
		if (v2[i] == v1[i])
			icnt++;
	}
	
	if(icnt == N)
		i_flag = true;
	if (dcnt == N)
		d_flag = true;

	if (i_flag)
		cout << "INCREASING\n";
	else if (d_flag)
		cout << "DECREASING\n";
	else
		cout << "NEITHER\n";

	return 0;
}
