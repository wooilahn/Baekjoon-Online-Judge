#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>'
#include <iostream>
#include <string>

using namespace std;

int main(){
  int T;
  cin >> T;

  while(T--){
    int p;
	cin >> p;

	int cur_v = 0;
	int max_v = -1;
	string s;
	string ans_s;

	for(int i=0; i<p; i++){
	 cin >> cur_v >> s;

	 if(cur_v > max_v){
	   ans_s = s;
	   max_v = cur_v;
	 }
	}

	cout << ans_s << endl;
  }

  return 0;
}
