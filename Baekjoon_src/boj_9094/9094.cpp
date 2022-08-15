#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int T, n, m;
  cin >> T;

  while(T--){
     cin >> n >> m;
	 int cnt = 0;

	 for(int i=1; i<n; i++){
	   for(int j=i+1; j<n; j++){
	     if((i*i+j*j+m) % (i*j) == 0)
		   cnt++;
	   }
	 }

	 cout << cnt << '\n';
  }


  return 0;
}
