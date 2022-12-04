#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){

  int T;
  scanf("%d", &T);

  while(T--){
    int N;
	scanf("%d", &N);

	while(N--){
	  long long a, b;
	  scanf("%lld %lld", &a, &b);
	  printf("%lld %lld\n", a+b, a*b);
	}
  }

  return 0;
}
