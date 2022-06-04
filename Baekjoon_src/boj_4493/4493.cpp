#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    int n;
	int score1=0, score2=0;
	string s;

	cin >> n;
	getline(cin, s);

	while(n--){
	  getline(cin, s);
	  char c1, c2;
	  c1 = s[0];
	  c2 = s[2];

	  if(c1 == 'R'){
	    if(c2 == 'P')
		  score2++;
		else if(c2 == 'S')
		  score1++;
	  }
	  else if(c1 == 'P'){
	    if(c2 == 'R')
		  score1++;
		else if(c2 == 'S')
		  score2++;
	  }
	  else if(c1 == 'S'){
	    if(c2 == 'R')
		  score2++;
		else if(c2 == 'P')
		  score1++;
	  }
	}

	if(score1 > score2)
	  cout << "Player 1\n";
	else if(score1 == score2)
	  cout << "TIE\n";
	else if(score1 < score2)
	  cout << "Player 2\n";
  }

  return 0;
}
