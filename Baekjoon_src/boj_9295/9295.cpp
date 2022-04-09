#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int a,b;
  for(int i=1; i<=T; i++){
    scanf("%d %d", &a, &b);
	printf("Case %d: %d\n", i, a+b);
  }

  return 0;
}
