#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int num;
  int S=0, T=0;

  for(int i=0; i<4; i++){
    cin >> num;
	S += num;
  }

  for(int i=0; i<4; i++){
    cin >> num;
	T += num;
  }

  cout << max(S, T) << endl;

  return 0;
}

