#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int arr1[27] = { 0 };
int arr2[27] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		arr1[s1[i] - 'a']++;
	}

	for (int i = 0; i < s2.size(); i++) {
		arr2[s2[i] - 'a']++;
	}

	int ans = 0;

	for (int i = 0; i < 27; i++) {
		ans += abs(arr1[i] - arr2[i]);
	}

	cout << ans << "\n";
	return 0;
}
