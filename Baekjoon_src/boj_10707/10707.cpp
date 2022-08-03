#include <iostream>
#define MIN(A,B) (A<B?A:B)

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A, B, C, D, P;

  cin >> A >> B >> C >> D >> P;

  int X_cost = A*P;
  int Y_cost = B;

  if(P > C){
    Y_cost += (P-C)*D;
  }

  cout << MIN(X_cost, Y_cost) << '\n';
  return 0;
}
