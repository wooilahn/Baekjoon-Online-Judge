#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int A, B;
  cin >> A >> B;

  cout << B-A << " " << B << "\n";
  return 0;
}
