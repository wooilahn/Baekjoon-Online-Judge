#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool check[10] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  string s;

  cin >> T;

  while(T--){
    cin >> s;
	memset(check, 0, sizeof(check));

	for(int i=0; i<s.size(); i++){
	  check[s[i]-'0'] = true;
	}

	int ans = 0;

	for(int i=0; i<10; i++){
	  if(check[i])
	    ans++;
	}
	cout << ans << endl;
  }
  
  return 0;
}
