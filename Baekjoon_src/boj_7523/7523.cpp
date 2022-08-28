#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    long long n, m;
	scanf("%lld %lld", &n, &m);

	long long sum = ((m-n+1)*(n+m))/2;

	printf("Scenario #%d:\n", i);
	printf("%lld\n\n", sum);
  }

  return 0;
}
