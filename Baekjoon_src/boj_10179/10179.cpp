#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  double cost;

  while(T--){
    scanf("%lf", &cost);
	printf("$%.2lf\n", cost*0.8); 
  }
  return 0;
}
