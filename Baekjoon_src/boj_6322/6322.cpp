#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  double a, b, c;
  
  for(int i=1;;i++){
	scanf("%lf %lf %lf", &a, &b, &c);
    if(a == 0 && b == 0 && c == 0)
	  break;

	printf("Triangle #%d\n", i);

	if(a == -1){
	  if(b >= c)
	    printf("Impossible.");
	  else {
		printf("a = ");
		printf("%.3lf", sqrt(c*c-b*b));
	  }
	  printf("\n");
	}
	else if(b == -1){
		if (a >= c)
			printf("Impossible.");
		else {
			printf("b = ");
			printf("%.3lf", sqrt(c*c - a*a));
		}
		printf("\n");
	}
	else if(c == -1){
	  printf("c = %.3lf\n", sqrt(a*a+b*b));
	}

	printf("\n");
  }
    
  return 0;
}
