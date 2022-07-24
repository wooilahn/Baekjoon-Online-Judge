#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;

  while(true){
    getline(cin, s);

	if(s[0] == '#')
	  break;

	int check_sum = 0;

	for(int i=0; i<s.size(); i++){
	  if(s[i] == ' ')
	    continue;

	  check_sum += (int(s[i]) - int('A') + 1) * (i+1);
	}

	printf("%d\n", check_sum);
  }

  return 0;
}
