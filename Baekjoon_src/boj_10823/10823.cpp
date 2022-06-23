#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string tmp;
  string s = "";
  int ans = 0;

  while(getline(cin, tmp)){
    for(int i=0; i<tmp.size(); i++){
	  if(tmp[i] == ','){
	    ans += stoi(s);
		s = "";
	  }
	  else
	    s += tmp[i];
	}
  }

  ans += stoi(s);
  printf("%d\n", ans);
  return 0;
}
