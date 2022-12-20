#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  double x1, y1, r1;
  double x2, y2, r2;

  scanf("%lf %lf %lf", &x1, &y1, &r1);
  scanf("%lf %lf %lf", &x2, &y2, &r2);

  double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

  if(r1 + r2 <= dist)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}
