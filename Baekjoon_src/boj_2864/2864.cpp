#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string A, B;

  cin >> A >> B;

  int min_v=0, max_v=0;

  for(int i=0; i<A.size(); i++){
    if(A[i] == '6')
	  A[i] = '5';
  }
  for(int i=0; i<B.size(); i++){
    if(B[i] == '6')
	  B[i] = '5';
  }
  min_v = stoi(A) + stoi(B);

  for(int i=0; i<A.size(); i++){
    if(A[i] == '5')
	  A[i] = '6';
  }
  for (int i = 0; i < B.size(); i++) {
	  if (B[i] == '5')
		  B[i] = '6';
  }
  max_v = stoi(A) + stoi(B);

  cout << min_v << " " << max_v << "\n";


  return 0;
}
