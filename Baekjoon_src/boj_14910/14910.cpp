#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  getline(cin, s);

  stringstream sstream(s);
  string token;

  bool flag = true;
  getline(sstream, token, ' ');
  int pre_num = stoi(token);
  int cur_num = 0;

  while(getline(sstream, token, ' ')){
    cur_num = stoi(token);

	if(pre_num > cur_num){
	  flag = false;
	  break;
	}
	else
	  pre_num = cur_num;
  }

  if(flag)
    cout << "Good\n";
  else
    cout << "Bad\n";

  return 0;
}
