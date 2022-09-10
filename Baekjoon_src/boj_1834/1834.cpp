#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

typedef long long ll;

int main(){
  ll N;
  scanf("%lld", &N);

  ll sum = 0;

  for(ll i=1; i<N; i++){
    sum += N*i + i;
  }

  printf("%lld\n", sum);

  return 0;
}
