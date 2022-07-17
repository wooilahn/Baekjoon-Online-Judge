#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  string s;
  for(int i=0; i<N; i++){
    cin >> s;
	v.push_back(s);
  }

  for(int i=0; i<v.size(); i++){
    reverse(v[i].begin(), v[i].end());
	cout << v[i] << endl;
  }

  return 0;
}
