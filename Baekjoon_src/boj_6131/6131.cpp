#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int ans = 0;

  for(int A=1; A<=500; A++){
	for(int B=1; B<=500; B++){
	  if(A*A - B*B == N)
	    ans++;
	  else if(A*A <= B*B)
	    break;
	}
  }

  printf("%d\n", ans);

  return 0;
}
