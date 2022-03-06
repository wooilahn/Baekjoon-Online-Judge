#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int n_cute = 0;
  int n_nocute = 0;

  int k;

  while(N--){
    scanf("%d", &k);

	if(k == 1)
	  n_cute++;
	else if(k == 0)
	  n_nocute++;
  }

  if(n_cute > n_nocute)
    printf("Junhee is cute!\n");
  else
    printf("Junhee is not cute!\n");

  return 0;
}
