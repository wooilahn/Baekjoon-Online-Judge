#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int S, M, L;
  scanf("%d %d %d", &S, &M, &L);

  int score = S + 2*M + 3*L;

  if(score >= 10)
    printf("happy\n");
  else
	printf("sad\n");

  return 0;
}
