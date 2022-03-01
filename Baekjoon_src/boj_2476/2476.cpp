#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int max(int A, int B){
  return A > B ? A : B;
}

int main(){
  int N;
  int A, B, C;

  scanf("%d", &N);

  int ans = 0;

  while(N--){
	  scanf("%d %d %d", &A, &B, &C);
	  int tmp = 0;

	  if(A == B && B == C)
	    tmp = 10000 + A*1000;
	  else if((A == B && B != C))
	    tmp = 1000 + A*100;
	  else if((B == C && A != C))
	    tmp = 1000 + B*100;
	  else if((A == C && B != C))
	    tmp = 1000 + C*100;
	  else
	    tmp = max(max(A,B), C) * 100;

	  ans = max(tmp, ans);
  }

  printf("%d\n", ans);

  return 0;
}
