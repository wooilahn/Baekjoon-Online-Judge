#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  long long N;
  long long cnt = 0;
  scanf("%lld", &N);

  while(N != 1){
    if(N % 2 == 0)
		N /= 2;
	else if(N % 2 == 1)
	    N += 1;
	cnt++;
  }

  printf("%lld\n", cnt);
  return 0;
}
