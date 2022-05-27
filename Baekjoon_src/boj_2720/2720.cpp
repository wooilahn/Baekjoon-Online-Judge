#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  int C, Q, D, N, P;

  while(T--){
    Q=0, D=0, N=0, P=0;
    cin >> C;

	Q = C/25;
	C -= Q*25;

	D = C/10;
	C -= D*10;

	N = C/5;
	C -= N*5;

	P = C/1;

	cout << Q << " " << D << " " << N << " " << P << endl;
  }

  return 0;
}
