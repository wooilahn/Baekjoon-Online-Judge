#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  string s1, s2;

  while(T--){
    int h_dist = 0;
    cin >> s1 >> s2;

	for(int i=0; i<s1.size(); i++){
	  if(s1[i] != s2[i])
	    h_dist++;
	}

	cout << "Hamming distance is " << h_dist << "." << endl;
  }

  return 0;
}
