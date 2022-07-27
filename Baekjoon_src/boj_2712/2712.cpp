#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  cout.precision(5);

  string s1, s2;
  while(T--){
    cin >> s1 >> s2;
	double q;
	
	cout.precision(4);
	if(s2 == "kg"){
	  q = stod(s1) * 2.2046;
	  
	  if(q != 0)
	    cout << fixed << q << " " << "lb" << '\n';
	  else
	    cout << "0.0000 lb\n";
	}
	else if(s2 == "lb"){
	  q = stod(s1) * 0.4536;

	  if(q != 0)
		cout << fixed << q << " " << "kg" << '\n';
	  else
	    cout << "0.0000 kg\n";
	}
	else if(s2 == "l"){
	  q = stod(s1) * 0.2642;

	  if(q != 0)
		cout << fixed << q << " " << "g" << '\n';
	  else
	    cout << "0.0000 g\n";
	}
	else if(s2 == "g"){
	  q = stod(s1) * 3.7854;

	  if(q != 0)
		cout << fixed << q << " " << "l" << '\n';
	  else
	    cout << "0.0000 l\n";
	}
  }

  return 0;
}
