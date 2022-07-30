#include <iostream>

using namespace std;
int arr[1005] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int M, N;
  cin >> N >> M;

  int A, B;
  while(M--){
    cin >> A >> B;
	arr[A]++;
	arr[B]++;
  }

  for(int i=1; i<=N; i++)
    cout << arr[i] << '\n';

  return 0;
}
