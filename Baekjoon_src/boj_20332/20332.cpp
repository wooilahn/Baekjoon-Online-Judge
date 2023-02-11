#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  long long n;
  long long tmp;
  long long sum = 0;

  scanf("%lld", &n);
  for(long long i=0; i<n; i++){
    scanf("%lld", &tmp);
	sum += tmp;
  }

  if(sum % 3 == 0)
    printf("yes\n");
  else
    printf("no\n");

  return 0;
}
