#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int student, apple;
  int ans = 0;
  for(int i=0; i<N; i++){
	scanf("%d %d", &student, &apple);
	ans += (apple % student);
  }

  printf("%d\n", ans);

  return 0;
}
