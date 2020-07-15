#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check[500002] = { 0 };
vector<string> dict;
vector<string> ans;

int main() {
	int N, M, cnt = 0;
	string s;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> s;
		dict.push_back(s);
	}


	sort(dict.begin(), dict.end());

	for (int i = 0; i < M; i++) {
		cin >> s;
		int low = 0, high = N - 1;
		
		while (true) {
			if (low <= high) {
				int mid = (low + high) / 2;
				if (s.compare(dict.at(mid)) == 0) {
					cnt++;
					ans.push_back(s);
					break;
				}
				else if (s.compare(dict.at(mid)) > 0) {
					low = mid + 1;
				}
				else if (s.compare(dict.at(mid)) < 0) {
					high = mid - 1;
				}
			}
			else 
				break;
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << endl;

	for (int i = 0; i < ans.size(); i++) 
		cout << ans.at(i) << endl;
	
	return 0;
}
