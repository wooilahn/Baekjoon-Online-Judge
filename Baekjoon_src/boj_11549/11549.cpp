#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int num = 0;
  int ans = 0;
  for(int i=0; i<5; i++){
    scanf("%d", &num);

	if(T == num)
	  ans++;
  }

  printf("%d\n", ans);
  return 0;
}
