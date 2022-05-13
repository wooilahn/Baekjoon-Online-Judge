#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  vector<int> v;

  for(int i=1; i<=5; i++){
    cin >> s;
	size_t n_pos = s.find("FBI");
	
	if(n_pos != -1)
	  v.push_back(i);
  }

  if(v.size() > 0){
    for(int i=0; i<v.size(); i++)
	  cout << v[i] << " ";
	cout << endl;
  }
  else
    cout << "HE GOT AWAY!" << endl;

  return 0;
}
