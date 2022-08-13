#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;

  while(n--){
    cin >> s;
	long long l = 0;
	int cur_dec = 1;

	for(int i=s.size()-1; i>=0; i--){
	  if(s[i]=='1')
	    l += cur_dec;
	  cur_dec *= 2;
	}
	
	cout << l << '\n';
  }

  return 0;
}
