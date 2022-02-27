#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int A, B;
  
  while(true){
    scanf("%d %d", &A, &B);

	if(A == 0 && B == 0)
	  return 0;

	if(A > B)
	  printf("Yes\n");
	else
	  printf("No\n");
  }

  return 0;
}
