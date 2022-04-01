#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<string, string>> v;

int main(){
  int n;
  scanf("%d", &n);

  string name;
  int d,m,y;

  for(int i=0; i<n; i++){
    cin >> name >> d >> m >> y;

	string s_y = to_string(y);
	string s_m = to_string(m);
	string s_d = to_string(d);

	if (s_m.size() == 1)
		s_m.insert(s_m.begin(), '0');
	if (s_d.size() == 1)
		s_d.insert(s_d.begin(), '0');

	string birth = s_y + s_m + s_d;
	
	v.push_back(make_pair(birth, name));
  }

  sort(v.begin(), v.end());

  cout << v[n-1].second << endl;
  cout << v[0].second << endl;

  return 0;
}
