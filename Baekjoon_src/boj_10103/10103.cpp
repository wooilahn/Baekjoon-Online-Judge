#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  int chang = 100;
  int sang = 100;
  int a,b;

  while(n--){
    scanf("%d %d", &a, &b);

	if(a == b)
	  continue;
	else if(a > b)
	  sang -= a;
	else if(a < b)
	  chang -= b;
  }

  printf("%d\n%d\n", chang, sang);

  return 0;
}
