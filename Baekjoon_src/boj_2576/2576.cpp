#define _CRT_SECURE_NO_WARNINGS
#define min(A,B) A>B?B:A
#include <stdio.h>

using namespace std;

int main(){
  int min_v = 999;
  int num, sum = 0;
  for(int i=0; i<7; i++){
    scanf("%d", &num);

	if(num%2 == 1){
	  sum += num;
	  min_v = min(min_v, num);
	}
  }

  if(min_v == 999)
    printf("-1\n");
  else
	printf("%d\n%d\n", sum, min_v);

  return 0;
}
