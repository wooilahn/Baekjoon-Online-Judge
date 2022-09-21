#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int e, f, c;
  scanf("%d %d %d", &e, &f, &c);

  int bottle = e+f;
  int ans = 0;

  while(bottle >= c){
    int tmp_bottle = 0;
	ans += bottle/c;
	tmp_bottle += bottle%c;
	tmp_bottle += bottle/c;
	bottle = tmp_bottle;
  }
  printf("%d\n", ans);

  return 0;
}
