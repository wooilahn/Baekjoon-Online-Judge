#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> sv;
vector<pair<pair<int,int>, string>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		sv.push_back(s);
	}

	sort(sv.begin(), sv.end());
	int idx = -1;

	if (sv[0].size() >= M) {
		int sz0 = sv[0].size();
		v.push_back(make_pair(make_pair(0, -sz0), sv[0]));
		idx = 0;
	}

	for (int i = 1; i < N; i++) {
		if (sv[i].size() < M)
			continue;

		if (sv[i] == sv[i-1]) { // 이전에 기록이 있을 때
			v[idx].first.first = v[idx].first.first - 1;
		}
		else { // 현재 기록이 없을 때
			idx = v.size();
			int curSz = sv[i].size();
			v.push_back(make_pair(make_pair(0, -curSz), sv[i]));
		}
	}

	sort(v.begin(), v.end());

	for (int i=0; i < v.size(); i++) {
		cout << v[i].second << '\n';
	}

	return 0;
}
