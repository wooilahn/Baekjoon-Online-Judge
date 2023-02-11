#include <stdio.h>

using namespace std;

int main(){
  long long T, N;
  scanf("%lld", &T);

  while(T--){
    scanf("%lld", &N);
	long long sqr_n = N*N;
	printf("%lld\n", sqr_n);
  }

  return 0;
}
