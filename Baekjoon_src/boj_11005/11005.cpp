#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, B;
  cin >> N >> B;

  vector<int> v;

  while(true){
    v.push_back(N%B);
	N/=B;

	if(N == 0)
	  break;
  }

  for(int k=v.size()-1; k>=0; k--){
    if(v[k] >= 10)
	  printf("%c", 'A'+v[k]-10);
	else
	  printf("%d", v[k]);
  }
  printf("\n");

  return 0;
}
