#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s1, s2, s3;
  int ans = 1;

  cin >> s1;
  char tar_c = s1[0];
  int cnt = 1;
  for(int i=1; i<s1.size(); i++){
    if(tar_c == s1[i])
	  cnt++;
	else{
	   tar_c = s1[i];
	   cnt = 1;
	}
	ans = max(cnt, ans);
  }
  cout << ans << endl;

  cin >> s2;
  ans = 1;
  cnt = 1;
  tar_c = s2[0];
  for(int i=1; i<s2.size(); i++){
    if(tar_c == s2[i])
	  cnt++;
	else {
	  tar_c = s2[i];
	  cnt = 1;
	}
	ans = max(cnt, ans);
  }
  cout << ans << endl;

  cin >> s3;
  ans = 1;
  cnt = 1;
  tar_c = s3[0];
  for(int i=1; i<s3.size(); i++){
    if(tar_c == s3[i])
	  cnt++;
	else {
	  tar_c = s3[i];
	  cnt = 1;
	}
	ans = max(cnt, ans);
  }
  cout << ans << endl;

  return 0;
}
