#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  long long K, N;
  scanf("%lld %lld", &K, &N);

  if(N == 1)
    printf("%d\n", -1);
  else{
    long long ans = (K*N) / (N-1);

	if( K*N % (N-1))
	  ans++;

	printf("%lld\n", ans);
  }
  return 0;
}
