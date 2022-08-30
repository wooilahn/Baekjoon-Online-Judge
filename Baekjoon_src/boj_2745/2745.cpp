#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string N;
  long long B;

  cin >> N;
  cin >> B;

  long long p = 1;
  long long sum = 0;

  for(int i=N.size()-1; i>=0; i--){
    if(N[i] >= '0' && N[i] <= '9')
	  sum += p * (N[i] - '0');
	else if(N[i] >= 'A' && N[i] <= 'Z')
	  sum += p * (10 + N[i] - 'A');

	p *= B;
  }

  cout << sum << '\n';

  return 0;
}
