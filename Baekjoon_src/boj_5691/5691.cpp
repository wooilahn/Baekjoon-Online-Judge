#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int A, B;

  while(true){
    scanf("%d %d", &A, &B);

	if(A == 0 && B == 0)
	  break;

	printf("%d\n", A-(B-A));
  }

  return 0;
}
