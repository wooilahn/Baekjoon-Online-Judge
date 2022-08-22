#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[105] = {0};

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  int i, j, k;
  for(int m=0; m<M; m++){
    scanf("%d %d %d", &i, &j, &k);
	
	for(int X=i; X<=j; X++)
	  arr[X] = k;
  }
  
  for(int X=1; X<=N; X++)
    printf("%d ", arr[X]);
  printf("\n");

  return 0;
}
