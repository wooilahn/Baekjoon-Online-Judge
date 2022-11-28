#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int L;
  char c;

  while(N--){
    scanf("%d %c", &L, &c);

	for(int i=0; i<L; i++){
	  printf("%c", c);
	}
	printf("\n");
  }

  return 0;
}
