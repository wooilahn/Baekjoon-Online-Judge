#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	string s;
	vector<string> v;

	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	bool flag = false;
	int sr = 0;
	int sc = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0 && i < N-1 && j > 0 && j < N-1) {
				if (v[i - 1][j] == '*' && v[i][j - 1] == '*' && v[i + 1][j] == '*' && v[i][j + 1] == '*') {
					sr = i;
					sc = j;
					flag = true;
					break;
				}
			}

			if (flag)
				break;
		}
	}

	int Lpal = 0;
	int Rpal = 0;
	int waist = 0;
	int Lleg = 0;
	int Rleg = 0;

	int wr = 0;
	int wc = 0;

	for (int t = 0; t < 5; t++) {
		int ssr = sr;
		int ssc = sc;

		int wwr = wr;
		int wwc = wc;

		if (t == 0) { // Lpal
			for (int c = ssc-1; c >= 0; c--) {
				if (v[ssr][c] == '*')
					Lpal++;
				else
					break;
			}
		}
		else if (t == 1) { // Rpal
			for (int c = ssc+1; c < N; c++) {
				if (v[ssr][c] == '*')
					Rpal++;
				else
					break;
			}
		}
		else if (t == 2) { // waist
			for (int r = ssr+1; r < N; r++) {
				if (v[r][ssc] == '*') {
					waist++;
				}
				else {
					wr = r-1;
					wc = ssc;
					break;
				}
			}
		}
		else if (t == 3) { // Lleg
			for (int r = wr + 1; r < N; r++) {
				if (v[r][wc - 1] == '*')
					Lleg++;
				else
					break;
			}
		}
		else if (t == 4) { // Rleg
			for (int r = wr + 1; r < N; r++) {
				if (v[r][wc + 1] == '*')
					Rleg++;
				else
					break;
			}
		}
	}

	sr++;
	sc++;

	cout << sr << " " << sc << "\n";
	cout << Lpal << " " << Rpal << " " << waist << " " << Lleg << " " << Rleg << "\n";
	return 0;
}
