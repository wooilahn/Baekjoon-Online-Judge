#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int M, F;

  while(true){
    scanf("%d %d", &M, &F);

	if(M == 0 && F == 0)
	  break;

	printf("%d\n", M+F);
  }

  return 0;
}
