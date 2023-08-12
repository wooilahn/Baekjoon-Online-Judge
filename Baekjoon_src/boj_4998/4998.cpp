#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	while (getline(cin, s)) {
		vector<string> v;
		stringstream sstream(s);
		string word;

		while (getline(sstream, word, ' ')) {
			v.push_back(word);
		}

		double N = stod(v[0]);
		double B = stod(v[1]);
		double M = stod(v[2]);

		int year = 0;

		while (true) {
			if (N > M) {
				cout << year << "\n";
				break;
			}
			
			year++;
			N = N + (N*(B/100));
		}
	}

	return 0;
}
