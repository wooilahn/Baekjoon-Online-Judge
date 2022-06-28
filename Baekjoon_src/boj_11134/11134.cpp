#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){
    int N, C;
	cin >> N >> C;
	int day = 0;

	if(N%C)
	  day++;
	day += N/C;

	cout << day << endl;
  }
}
