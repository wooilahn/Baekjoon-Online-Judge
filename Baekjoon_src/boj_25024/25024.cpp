#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int x, y;
	bool time_enable = false;
	bool date_enable = false;

	scanf("%d %d", &x, &y);

	if(0<=x && x<=23 && 0<=y && y<=59)
	  time_enable = true;

	if(x == 1 || x == 3 || x == 5 || x == 7 ||  x == 8 || x == 10 || x == 12){
	  if(1 <= y && y <= 31)
	    date_enable = true;
	}
	else if(x == 4 || x == 6 || x == 9 || x == 11){
	  if(1 <= y && y <= 30)
	    date_enable = true;
	}
	else if(x == 2){
	  if(1 <= y && y <= 29)
	    date_enable = true;
	}

	if(time_enable)
	  printf("Yes ");
	else
	  printf("No ");

	if(date_enable)
	  printf("Yes\n");
	else
	  printf("No\n");
  }

  return 0;
}
