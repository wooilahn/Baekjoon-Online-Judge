#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n;
  getline(cin, s);

  while(n--){
	int conson = 0;
	int vowels = 0;
    getline(cin, s);

	for(int i=0; i<s.size(); i++){
	  if(s[i] == ' ')
	    continue;

	  if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
	     || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
	    vowels++;
	  else
	    conson++;
	}
	printf("%d %d\n", conson, vowels);
  }

  return 0;
}
