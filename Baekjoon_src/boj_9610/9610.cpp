#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n;

  scanf("%d", &n);
  
  int x,y;

  int q1 = 0;
  int q2 = 0;
  int q3 = 0;
  int q4 = 0;
  int axis = 0;

  while(n--){
    scanf("%d %d", &x, &y);

	if(x == 0 || y == 0)
	  axis++;
	else if(x > 0 && y > 0)
	  q1++;
	else if(x < 0 && y > 0)
	  q2++;
	else if(x < 0 && y < 0)
	  q3++;
	else if(x > 0 && y < 0)
	  q4++;
  }

  printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d\n", q1, q2, q3, q4, axis);
  return 0;
}
