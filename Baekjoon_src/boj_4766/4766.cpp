#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  double a, b;

  scanf("%lf", &a);

  while(true){
    scanf("%lf", &b);

	if(b == 999)
	  break;

	printf("%.2lf\n", b-a);

	double tmp;
	tmp = b;
	b = a;
	a = tmp;
  }

  return 0;
}
