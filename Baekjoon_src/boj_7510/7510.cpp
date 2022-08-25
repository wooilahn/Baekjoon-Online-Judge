#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  for(int i=1; i<=T; i++){
    int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	bool flag = false;

	if(a*a == b*b + c*c)
	  flag = true;
	else if(b*b == a*a + c*c)
	  flag = true;
	else if(c*c == a*a + b*b)
	  flag = true;

	printf("Scenario #%d:\n", i);
	if(flag)
	  printf("yes\n\n");
	else
	  printf("no\n\n");
  }
  return 0;
}
