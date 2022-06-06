#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;

  cin >> a >> b;

  if(a > 2)
    cout << "After\n";
  else if(a == 2){
    if(b < 18)
	  cout << "Before\n";
	else if(b == 18)
	  cout << "Special\n";
	else
	  cout << "After\n";
  }
  else
    cout << "Before\n";

  return 0;
}
