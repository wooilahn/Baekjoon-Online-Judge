#include <iostream>
#include <math.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, W, H;
  double num;
  cin >> N >> W >> H;

  double max_l = sqrt(W*W + H*H);

  while(N--){
    cin >> num;

	if(max_l < num)
	  cout << "NE" << endl;
	else
	  cout << "DA" << endl;
  }

  return 0;
}
