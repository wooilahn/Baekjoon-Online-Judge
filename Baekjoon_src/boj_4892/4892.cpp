#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int cnt = 1;

  while(true){
    cin >> n;

	if(n == 0)
	  break;

	int target = n*3;
	bool flag = false;

	if(target % 2 == 0){
	  target /= 2;
	  flag = true;
	}
	else if(target % 2 == 1)
	  target = (target+1)/2;

	target *= 3;
	target /= 9;

	if(flag)
	  cout << cnt << ". even " << target << '\n';
	else
	  cout << cnt << ". odd " << target << '\n';

	cnt++;
  }

  return 0;
}
