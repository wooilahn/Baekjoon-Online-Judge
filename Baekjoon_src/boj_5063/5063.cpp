#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int r,e,c;

  while(N--){
    scanf("%d %d %d", &r, &e, &c);

	if(e-c > r)
	  printf("advertise\n");
	else if(e-c < r)
	  printf("do not advertise\n");
	else if(e-c == r)
	  printf("does not matter\n");
  }

  return 0;
}
