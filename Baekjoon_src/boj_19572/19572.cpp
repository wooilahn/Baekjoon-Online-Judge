#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  double d1, d2, d3;
  scanf("%lf %lf %lf", &d1, &d2, &d3);

  double sum = (d1 + d2 + d3) / 2;

  double x, y, z;
  
  z = sum - d1;
  y = sum - d2;
  x = sum - d3;

  if(x <= 0 || y <= 0 || z <= 0)
    printf("-1\n");
  else{
    printf("1\n");
	printf("%.1lf %.1lf %.1lf\n", x, y, z);
  }

  return 0;
}
