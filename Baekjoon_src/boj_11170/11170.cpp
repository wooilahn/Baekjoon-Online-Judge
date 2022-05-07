#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  int N, M;
  while(T--){
    cin >> N >> M;

	int n_zero = 0;
	for(int i=N; i<=M; i++){
	  string s = to_string(i);

	  for(int i=0; i<s.size(); i++){
	    if(s[i] == '0')
		  n_zero++;
	  }
	}

	cout << n_zero << endl;
  }

  return 0;
}
