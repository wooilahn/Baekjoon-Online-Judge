#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, sum = 0;
  scanf("%d", &N);

  int num, succ = 0;
  for(int i=0; i<N; i++){
    scanf("%d", &num);

	if(num == 0)
	  succ = 0;
	else if(num == 1){
	  succ++;
	  sum += succ;
	}
  }

  printf("%d\n", sum);

  return 0;
}
