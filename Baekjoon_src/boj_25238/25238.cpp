#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  double a, b;
  scanf("%lf %lf", &a, &b);

  double d_ratio = a - (double)(a * (b/100));

  if(d_ratio >= 100)
    printf("0\n");
  else
    printf("1\n");

	return 0;
}
