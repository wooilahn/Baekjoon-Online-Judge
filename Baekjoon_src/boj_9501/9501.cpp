#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  int N, D;

  while(T--){
    cin >> N >> D;
	int v, f, c;
	int cnt = 0;

	for(int i=0; i<N; i++){
	  cin >> v >> f >> c;
	  double dist = (double)v * (double)(f) / (double)(c);
	  
	  if(dist >= (double)D)
	    cnt++;
	}

	cout << cnt << '\n';
  }

  return 0;
}
