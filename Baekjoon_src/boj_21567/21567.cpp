#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[10] = {0};

int main(){
  long long A, B, C;
  scanf("%lld %lld %lld", &A, &B, &C);

  long long res = A*B*C;

  while(res != 0){
    arr[res%10]++;
    res /= 10;
  }

  for(int i=0; i<10; i++)
    printf("%d\n", arr[i]);

  return 0;
}
