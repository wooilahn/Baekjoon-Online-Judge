#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int a, b, c;

int main(){
  scanf("%d %d %d", &a, &b, &c);

  if(a+b == c)
	printf("%d+%d=%d\n", a,b,c);
  else if(a == b+c)
    printf("%d=%d+%d\n", a,b,c);
  else if(a-b == c)
    printf("%d-%d=%d\n", a,b,c);
  else if(a == b-c)
    printf("%d=%d-%d\n", a,b,c);
  else if(a*b == c)
    printf("%d*%d=%d\n", a,b,c);
  else if(a == b*c)
    printf("%d=%d*%d\n", a,b,c);
  else if(a == b/c)
    printf("%d=%d/%d\n", a,b,c);
  else if(a/b == c)
    printf("%d/%d=%d\n", a,b,c);

  return 0;
}
