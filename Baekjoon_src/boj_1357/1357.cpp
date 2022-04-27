#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string X, Y;
  cin >> X;
  cin >> Y;

  reverse(X.begin(), X.end());
  reverse(Y.begin(), Y.end());

  int sum = 0;
  int mul = 1;

  for(int i=0; i<X.length(); i++){
    sum += mul * int(X.at(X.length()-1-i)-'0');
	mul *= 10;
  }


  mul = 1;
  for(int i=0; i<Y.length(); i++){
    sum += mul * int(Y.at(Y.length()-1-i)-'0');
	mul *= 10;
  }

  string ans_s = to_string(sum);
  reverse(ans_s.begin(), ans_s.end());
  
  bool flag = false;
  for(int i=0; i<ans_s.length(); i++){
    if(flag == false && ans_s.at(i) == '0')
	  continue;

	if(ans_s.at(i) != '0'){
	  flag = true;
	  cout << ans_s.at(i);
	  continue;
	}

	cout << ans_s.at(i);
  }
  cout << endl;

  return 0;
}
