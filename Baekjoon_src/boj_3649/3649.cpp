#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, n, num;

	while (cin >> x >> n) { // EOF 될 때까지, 입력받기
		vector<int> v;

		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());
		int width = x * pow(10, 7);

		int left = 0;
		int right = n - 1;

		bool flag = false;
		int block1, block2;

		while (left < right) {
			int sBlock = v[left] + v[right];

			if (sBlock > width) {
				right--;
			}
			else if (sBlock < width) {
				left++;
			}
			else {
				block1 = v[left];
				block2 = v[right];
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "yes " << block1 << " " << block2 << "\n";
		}
		else {
			cout << "danger\n";
		}	
	}

	return 0;
}
