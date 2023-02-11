#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char map[25][250] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int c;
  cin >> c;

  string s;
  cin >> s;

  int r = s.size() / c;

  int idx = 0;
  bool flag = true;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
		if(flag == true){
		  map[i][j] = s[idx++];
		}
		else if(flag == false){
		  map[i][c-1-j] = s[idx++];
		}
	}

	flag = !flag;
  }

  for(int i=0; i<c; i++){
    for(int j=0; j<r; j++){
	  cout << map[j][i];
	}
  }
  cout << "\n";


  return 0;
}
