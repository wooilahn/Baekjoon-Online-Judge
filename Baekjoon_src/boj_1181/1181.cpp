#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, string>> w;

int main() {

	string s;
	int N, len;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		//scanf("%s", str);
		cin >> s;
		len = s.size();
		w.push_back(make_pair(len, s));
	}

	sort(w.begin(), w.end());

	for (int i = 0;i < N;i++) {
		if (i > 0) {
			if(w.at(i).second == w.at(i-1).second)
				continue;
		}
		cout << w.at(i).second << endl;
	}
	
	return 0;
}
