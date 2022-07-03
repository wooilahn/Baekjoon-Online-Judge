#include <iostream>
#include <string>

using namespace std;

int check[29] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while(getline(cin, s)){
    for(int i=0; i<s.size(); i++)
	  check[s[i]-'a']++;
  }

  int max_v = -1;
  string ans = "";

  for(int i=0; i<27; i++){
    if(max_v < check[i]){
	  ans = "";
	  max_v = check[i];
	  ans.push_back(char('a'+i));
	}
	else if(max_v == check[i])
	  ans.push_back(char('a'+i));
  }

  cout << ans << endl;

  return 0;
}
