#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  string s;

  cin >> n;

  while(n--){
    cin >> s;

	int s1, s2;

	s1 = (s[0]-'A')*26*26 + (s[1]-'A')*26 + s[2]-'A';
	s2 = atoi(s.substr(4).c_str());

	int s3 = abs(s1-s2);

	if(s3 <= 100)
	  cout << "nice" << endl;
	else
	  cout << "not nice" << endl;
  }
  

  return 0;
}
