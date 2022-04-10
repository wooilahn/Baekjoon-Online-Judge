#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int V, E;
  while(T--){
    scanf("%d %d", &V, &E);
	printf("%d\n", 2-V+E);
  }

  return 0;
}
