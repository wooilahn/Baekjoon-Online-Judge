#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n, k;
  scanf("%d", &n);

  while(n--){
	scanf("%d", &k);

	for(int t=0; t<k; t++){
	  printf("=");
	}
	printf("\n");
  }

  return 0;
}
