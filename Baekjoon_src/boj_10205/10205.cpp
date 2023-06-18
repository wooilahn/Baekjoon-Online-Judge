#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> K;

	int h;
	string s;

	for(int i=1; i<=K; i++) {
		cin >> h;
		cin >> s;

		for (int t = 0;t < s.size(); t++) {
			if (s[t] == 'c')
				h++;
			else if (s[t] == 'b')
				h--;

			if (h == 0)
				break;
		}

		cout << "Data Set " << i << ":\n";
		cout << h << "\n\n";
	}


	return 0;
}
