#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  bool flag = false;
  int N;
  scanf("%d", &N);

  int E;
  scanf("%d", &E);

  int ee;

  for(int i=1; i<N; i++){
	scanf("%d", &ee);

	if(E < ee){
		flag = true;
	}
  }

  if(flag)
    printf("N\n");
  else
    printf("S\n");

  return 0;
}
