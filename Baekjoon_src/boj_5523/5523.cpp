#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int win_A=0, win_B=0;
  int score_A, score_B;

  while(N--){
    cin >> score_A >> score_B;

	if(score_A > score_B)
	  win_A++;
	else if(score_A < score_B)
	  win_B++;
  }

  cout << win_A << " " << win_B << endl;
  return 0;
}
