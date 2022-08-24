#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n, T, num;
  scanf("%d %d", &n, &T);

  int sum = 0;

  for(int i=1; i<=n; i++){
	scanf("%d", &num);
	sum += num;

	if(sum > T){
	  printf("%d\n", i-1);
	  break;
	}
	if(i == n)
	  printf("%d\n", i);
  }

  return 0;
}
