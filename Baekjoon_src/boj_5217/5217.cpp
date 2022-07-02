#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int num;
  while(T--){
    scanf("%d", &num);

	printf("Pairs for %d:", num);
	int cnt = 0;

	for(int i=1; i<=num/2; i++){
	  if(num-i != i && num-i > i){
	    if(cnt > 0)
		  printf(",");

	    printf(" %d %d", i, num-i);

		cnt++;
	  }
	}
	printf("\n");
  }

  return 0;
}
