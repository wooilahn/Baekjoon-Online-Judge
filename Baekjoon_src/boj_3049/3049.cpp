#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  
  if(N == 3)
    cout << "0" << endl;
  else
    cout << (N*(N-1)*(N-2)*(N-3))/24 << endl;

  return 0;
}
