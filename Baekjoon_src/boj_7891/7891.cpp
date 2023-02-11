#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  while(N--){
    int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a+b);
  }

  return 0;
}
