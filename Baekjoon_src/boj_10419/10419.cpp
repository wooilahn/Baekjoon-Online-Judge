#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){
    int n;
	cin >> n;

	for(int i=1; i<=n; i++){
	  if(i + i*i > n) {
	    cout << i-1 << '\n';
		break;
	  }
	}
  }

  return 0;
}
