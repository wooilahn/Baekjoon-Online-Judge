#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int y = 0;
    int k = 0;

    int a, b;

    for(int i=0; i<9; i++){
      scanf("%d %d", &a, &b);
      y += a;
      k += b;
    }

    if(y > k)
      printf("Yonsei\n");
    else if(y < k)
      printf("Korea\n");
    else if(y == k)
      printf("Draw\n");
  }

  return 0;
}
