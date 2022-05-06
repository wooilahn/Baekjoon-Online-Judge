#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  string s1, s2;
  while(T--){
    cin >> s1 >> s2;

	cout << "Distances:";
	for(int i=0; i<s1.size(); i++){
	  int dist = 0;

	  if(s2[i] >= s1[i])
	    dist = s2[i] - s1[i];
	  else
	    dist = s2[i] + 26 - s1[i];

	  cout << " " << dist;
	}
	cout << endl;
  }

  return 0;
}
