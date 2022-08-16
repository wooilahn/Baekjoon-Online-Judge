#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  string s;
  getline(cin, s);

  while(T--){
    getline(cin, s);
	stringstream ss(s);

	string token;
	vector<string> v;

	while(getline(ss, token, ' ' ))
	  v.push_back(token);

	v.push_back(v[0]);
	v.push_back(v[1]);

	for(int i=2; i<v.size(); i++){
	  cout << v[i];

	  if(i != v.size()-1)
	    cout << " "; 
	}
	cout << "\n";
  }

  return 0;
}
