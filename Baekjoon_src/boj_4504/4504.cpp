#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, num;
  cin >> n;

  while(true){
    cin >> num;

	if(num == 0)
	  break;

	if(num % n == 0)
	  cout << num << " is a multiple of " << n << ".";
	else
	  cout << num << " is NOT a multiple of " << n << ".";
	cout << endl;
  }

  return 0;
}
