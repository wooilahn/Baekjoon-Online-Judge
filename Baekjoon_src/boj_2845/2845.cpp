#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int L, P;
  int arr[15] = {0};

  cin >> L >> P;

  for(int i=0; i<5; i++)
    cin >> arr[i];

  for(int i=0; i<5; i++)
    cout << arr[i]-(L*P) << " ";
  cout << endl;

  return 0;
}
