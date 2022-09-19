#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  int row=1, col=1;

  bool flag = false;
  while(n--){
    if(!flag)
	  row++;
	else
	  col++;
	flag = !flag;
  }

  printf("%d\n", row*col);

  return 0;
}
