#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int n;

  while(cin >> s >> n){
	cout << s << " " << n << " = ";
	vector<char> v;

	for(int i=0; i<s.size(); i++)
		v.push_back(s[i]);

	bool flag = false;
	int cnt = 1;

	do {
	    if(cnt == n){
		  for(int i=0; i<v.size(); i++)
		    cout << v[i];
		  cout << "\n";
		  flag = true;
		  break;
		}

		cnt++;
	} while(next_permutation(v.begin(), v.end()));

	if(!flag){
		cout << "No permutation\n";
	}
  }

  return 0;
}
