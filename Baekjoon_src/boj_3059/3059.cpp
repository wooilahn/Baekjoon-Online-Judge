#include <iostream>
#include <string>
#include <string.h>

using namespace std;
bool check[30];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){
      memset(check, 0, sizeof(check));
      string s;
      cin >> s;

      for(int i=0; i<s.size(); i++){
        if(check[s[i]-'A'] == false)
          check[s[i]-'A'] = true;
      }

      int ans = 0;
      for(int i=0; i<=25; i++){
          if(!check[i])
            ans += (i+65);
      }

      cout << ans << endl;
  }

  return 0;
}
