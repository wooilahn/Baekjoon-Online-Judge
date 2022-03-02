#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

char score[5] = {0};

int main(){
  scanf("%s", score);

  double ans = 0.0;

  if(score[0] == 'A')
    ans = 4.0;
  else if(score[0] == 'B')
    ans = 3.0;
  else if(score[0] == 'C')
    ans = 2.0;
  else if(score[0] == 'D')
    ans = 1.0;
  else if(score[0] == 'F'){
    printf("0.0\n");
	return 0;
  }

  if(score[1] == '+')
    ans += 0.3;
  else if(score[1] == '0')
    ans += 0.0;
  else if(score[1] == '-')
    ans -= 0.3;

  printf("%.1lf\n", ans);

  return 0;
}
