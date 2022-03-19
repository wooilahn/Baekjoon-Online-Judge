#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char ans[105] = {0};
char univ[105] = {0};
int L;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int N;
    int max_L = -1;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
      scanf("%s %d", univ, &L);
      
      if(L > max_L){
        max_L = L;
        memset(ans, 0, sizeof(ans));
        strcpy(ans, univ);
      }
    }
    printf("%s\n", ans);
  }
  return 0;
}

