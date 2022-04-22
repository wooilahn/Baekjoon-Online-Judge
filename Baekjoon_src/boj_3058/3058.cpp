#define _CRT_SECURE_NO_WARNINGS
#define min(a,b) a<b ? a:b
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
  int T, num;
  scanf("%d", &T);

  while(T--){
    int sum = 0;
    int min_v = 999;

	for(int i=0; i<7; i++){
	  scanf("%d", &num);

	  if(num % 2 == 0){
	    sum += num;
		min_v = min(min_v, num);
	  }
	}

	printf("%d %d\n", sum, min_v);
  }

  return 0;
}
