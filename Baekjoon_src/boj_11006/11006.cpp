#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int N, M;

  while(T--){
    cin >> N >> M;
	cout << 2*M-N << " " << N-M << endl;
  }
  
  return 0;
}
