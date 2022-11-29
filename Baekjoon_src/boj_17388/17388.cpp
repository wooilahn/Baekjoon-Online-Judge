#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
  int ss, kr, hy;
  scanf("%d %d %d", &ss, &kr, &hy);

  if(ss+kr+hy >= 100)
    printf("OK\n");
  else {
    int min_v = min(ss, min(kr, hy));

	if(min_v == ss)
	  printf("Soongsil\n");
	else if(min_v == kr)
	  printf("Korea\n");
	else if(min_v == hy)
	  printf("Hanyang\n");
  }

  return 0;
}
