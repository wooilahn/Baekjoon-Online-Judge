#define MIN(A,B) A > B ? B : A
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  long long C, K, P;
  scanf("%lld %lld %lld", &C, &K, &P);

  long long sum = 0;

  for(int i=0; i<=C; i++){
    sum += K*i + P*i*i;
  }

  printf("%lld\n", sum);

  return 0;

}
