#include <iostream>

using namespace std;

void dec_to_bin(long long num){
  if(num == 0 || num == 1)
    cout << num;
  else {
    dec_to_bin(num/2);
	cout << num % 2;
  }

  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n;
  cin >> n;
  dec_to_bin(n);
  cout << endl;

  return 0;
}
