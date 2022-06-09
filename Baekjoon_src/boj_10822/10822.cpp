#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  
  int start_idx = 0;
  int last_idx = 0;
  int sum = 0;

  for(int i=0;i<s.size();i++){
    
	if(s[i] == ','){
	  last_idx = i;
	  sum += atoi(s.substr(start_idx, last_idx-start_idx).c_str());
	  start_idx = i + 1;
	}
  }
  
  sum += atoi(s.substr(start_idx, s.size()).c_str());
  cout << sum << endl;

  return 0;
}
