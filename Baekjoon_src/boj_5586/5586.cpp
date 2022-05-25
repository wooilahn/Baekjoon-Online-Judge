#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int joi_cnt = 0;
  int ioi_cnt = 0;

  for(int i=0; i<s.size(); i++){
    if(s.substr(i, 3).compare("JOI") == 0)
	  joi_cnt++;
	else if(s.substr(i,3).compare("IOI") == 0)
	  ioi_cnt++;
  }

  cout << joi_cnt << endl << ioi_cnt << endl;

  return 0;
}
