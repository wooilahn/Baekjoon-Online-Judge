#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	string s1, s2;

	while (T--) {
		cin >> s1 >> s2;

		int arr1[27] = { 0 };
		int arr2[27] = { 0 };

		for (int i = 0; i < s1.size(); i++) 
			arr1[s1[i] - 'a']++;
		
		for (int i = 0; i < s2.size(); i++) 
			arr2[s2[i] - 'a']++;
		

		bool flag = false;

		for (int i = 0; i < 27; i++) {
			if (arr1[i] != arr2[i]) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << s1 << " & " << s2 << " are NOT anagrams.\n";
		else
			cout << s1 << " & " << s2 << " are anagrams.\n";
	}

	return 0;
}
