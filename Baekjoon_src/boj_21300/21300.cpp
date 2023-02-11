#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int ans = 0;
  int n = 0;

  for(int i=0; i<6; i++){
    scanf("%d", &n);
	ans += n;
  }

  printf("%d\n", ans*5);

  return 0;
}
