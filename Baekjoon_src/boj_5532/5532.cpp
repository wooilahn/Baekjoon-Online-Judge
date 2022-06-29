#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int L, A, B, C, D;

  cin >> L >> A >> B >> C >> D;

  cout << L - max((A+C-1)/C, (B+D-1)/D) << endl;

  return 0;
}
