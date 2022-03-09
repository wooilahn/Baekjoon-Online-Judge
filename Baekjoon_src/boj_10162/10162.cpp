#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool t_flag = false;
int n_A = 0;
int n_B = 0;
int n_C = 0;

int main(){
  int T;
  scanf("%d", &T);

  if(T%10 != 0) {
    printf("-1\n");
    return 0;
  }

  int n_A = T/300;
  T -= n_A * 300;
  int n_B = T/60;
  T -= n_B * 60;
  int n_C = T/10;
  T -= n_C * 10;

  printf("%d %d %d\n", n_A, n_B, n_C);

  return 0;
}
