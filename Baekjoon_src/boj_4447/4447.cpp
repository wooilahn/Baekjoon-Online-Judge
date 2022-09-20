#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  string s;
  getline(cin, s);

  while(n--){
    getline(cin, s);
	int g_cnt = 0;
	int b_cnt = 0;

	for(int i=0; i<s.size(); i++){
	  if(s[i] == 'g' || s[i] == 'G')
	    g_cnt++;
	  else if(s[i] == 'b' || s[i] == 'B')
	    b_cnt++;
	}

	cout << s << " is ";

	if(g_cnt > b_cnt)
	  cout << "GOOD\n";
	else if(g_cnt < b_cnt)
	  cout << "A BADDY\n";
	else if(g_cnt == b_cnt)
	  cout << "NEUTRAL\n";
  }

  return 0;
}
