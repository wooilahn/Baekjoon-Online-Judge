#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
bool check[26] = {false};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;

  while(true){
    memset(check, 0, sizeof(check));
    getline(cin, s);

	if(s[0] == '*')
	  break;

	for(int i=0; i<s.size(); i++){
	  if(s[i] == ' ')
	    continue;

	  check[s[i]-'a'] = true;
	}

	bool flag = true;

	for(int i=0; i<26; i++){
	  if(!check[i]){
	    flag = false;
		break;
	  }
	}
	
	if(flag)
	  cout << "Y" << endl;
	else
	  cout << "N" << endl;
  }

  return 0;
}
