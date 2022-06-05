#include <iostream>

using namespace std;

int A[10] = {0};
int B[10] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i=0; i<10; i++)
    scanf("%d", &A[i]);
  
  for(int i=0; i<10; i++)
    scanf("%d", &B[i]);

  int win_A = 0;
  int win_B = 0;

  for(int i=0; i<10; i++){
    if(A[i] > B[i])
	  win_A++;
	else if(A[i] < B[i])
	  win_B++;
  }

  if(win_A > win_B)
    cout << "A" << endl;
  else if(win_A < win_B)
    cout << "B" << endl;
  else
    cout << "D" << endl;

  return 0;
}
