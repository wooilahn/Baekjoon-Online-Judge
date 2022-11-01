#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  long long A, B;
  scanf("%lld %lld", &A, &B);

  if(A == B){
    printf("0\n");
	return 0;
  }
  else if(A > B){
    long long tmp = A;
	A = B;
	B= tmp;
  }

  printf("%lld\n", B-A-1);

  for(long long i=A+1; i<B; i++){
    printf("%lld ", i);
  }
  printf("\n");

  return 0;
}
