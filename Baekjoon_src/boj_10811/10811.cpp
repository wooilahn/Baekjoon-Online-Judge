#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[105] = {0};

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  for(int i=1; i<=N; i++)
    arr[i] = i;

  int i, j;
  for(int m=0; m<M; m++){
    scanf("%d %d", &i, &j);


	for(int k=0; k<=(j-i)/2; k++){
	  int tmp = arr[i+k];
	  arr[i+k] = arr[j-k];
	  arr[j-k] = tmp;
	}
  }

  for(int i=1; i<=N; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
