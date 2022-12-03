#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	bool flag = true;

	for(int i=0; i<3; i++){
	  if(s[i] != '5'){
		flag = false;
		break;
	  }
	}

	if(flag)
	  printf("YES\n");
	else
	  printf("NO\n");

	return 0;
}
