#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int L, R, A;
  int ans = 0;

  scanf("%d %d %d", &L, &R, &A);

  if(L > R){
    ans += min(L, R+A);
    A -= (ans - R);
    ans += A / 2; 
  }
  else if(L < R){
    ans += min(L+A, R);
    A -= (ans - L);
    ans += A / 2;
  }
  else if(L == R){
    ans += L;
    ans += A/2;
  }

  ans *= 2;
  printf("%d\n", ans);
  return 0;
}
