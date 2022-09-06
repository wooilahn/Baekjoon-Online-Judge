#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> hole;

int main(){
  int N, L;
  scanf("%d %d", &N, &L);
  hole.resize(N);

  for(int i=0; i<N; i++){
    scanf("%d", &hole[i]);
  }

  sort(hole.begin(), hole.end());
 
  int cur_tape = hole[0];
  int ans = 1;

  for(int i=1; i<N; i++){
    if(hole[i]-cur_tape+1 > L){
	  cur_tape = hole[i];
	  ans++;
	}
  }

  printf("%d\n", ans);

  return 0;
}
