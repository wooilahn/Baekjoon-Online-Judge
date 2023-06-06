#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	
	while (getline(cin, s)) {
		string s1, s2;
		
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				s1 = s.substr(0, i);
				s2 = s.substr(i+1, s.size()-1);

				break;
			}
		}

		int d1 = stod(s1);
		int d2 = stod(s2);

		printf("%.2lf\n", (double)d1 / (double)d2);
	}

	return 0;
}
