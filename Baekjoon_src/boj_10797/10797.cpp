#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int num, ans = 0;
  for(int i=0; i<5; i++){
    scanf("%d", &num);

	if(num == N)
	  ans++;
  }

  printf("%d\n", ans);

  return 0;
}
