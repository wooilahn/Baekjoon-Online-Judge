#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while(n--){
    string s;
	int score;

	cin >> s >> score;
	cout << s << " ";

	if(97 <= score && score <= 100)
	  cout << "A+\n";
	else if(90 <= score && score <= 96)
	  cout << "A\n";
	else if(87 <= score && score <= 89)
	  cout << "B+\n";
	else if(80 <= score && score <= 86)
	  cout << "B\n";
	else if(77 <= score && score <= 79)
	  cout << "C+\n";
	else if(70 <= score && score <= 76)
	  cout << "C\n";
	else if(67 <= score && score <= 69)
	  cout << "D+\n";
	else if(60 <= score && score <= 66)
	  cout << "D\n";
	else if(0 <= score && score <= 59)
	  cout << "F\n";
  }

  return 0;
}
