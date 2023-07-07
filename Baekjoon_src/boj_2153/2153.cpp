#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool et[10005] = { 0 };

void eratos() {

	for (int i = 2; i <= 10000; i++) {
		if (!et[i]) {
			for (int k = i + i; k <= 10000; k += i) {
				et[k] = true;
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sum = 0;
	string s;

	cin >> s;
	eratos();

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			sum += s[i] - 'a' + 1;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			sum += s[i] - 'A' + 27;

	}

	if (et[sum])
		cout << "It is not a prime word.\n";
	else
		cout << "It is a prime word.\n";

	return 0;
}
