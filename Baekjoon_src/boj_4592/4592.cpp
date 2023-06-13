#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int map[105] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;

	vector<int> v;

	while (true) {
		cin >> N;
		memset(map, 0, sizeof(map));
		v.clear();

		if (N == 0)
			break;

		int num;
		for (int k = 0; k < N; k++) {
			cin >> num;
			v.push_back(num);
		}

		
		for (int k = 0; k < v.size(); k++) {
			if (k == 0)
				cout << v[k] << " ";
			else {
				if (v[k - 1] != v[k])
					cout << v[k] << " ";
			}
		}
		cout << "$\n";
	}

	return 0;
}
