#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int D, M;
  scanf("%d %d", &D, &M);

  int diff_day = 0;
  diff_day = D-1;

  if(M > 1) {
    for(int i=1; i<M; i++){
	  if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
	    diff_day += 31;
	  else if(i == 4 || i == 6 || i == 9 || i == 11)
	    diff_day += 30;
	  else if(i == 2)
	    diff_day += 28;
	}
  }

  // 1, 3, 5, 7, 8, 10, 12 (31)
  // 4, 6, 9, 11 (30)
  // 2 (28)

  diff_day %= 7;

  if(diff_day == 0)
    printf("Thursday\n");
  else if (diff_day == 1)
	  printf("Friday\n");
  else if (diff_day == 2)
	  printf("Saturday\n");
  else if (diff_day == 3)
	  printf("Sunday\n");
  else if (diff_day == 4)
	  printf("Monday\n");
  else if (diff_day == 5)
	  printf("Tuesday\n");
  else if (diff_day == 6)
	  printf("Wednesday\n");

  return 0;
}
