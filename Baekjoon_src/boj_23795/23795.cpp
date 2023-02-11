#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  
  int ans = 0;
  int n;

  while(true){
    scanf("%d", &n);

	if(n == -1)
	  break;

	ans += n;
  }

  printf("%d\n", ans);
  return 0;
}
