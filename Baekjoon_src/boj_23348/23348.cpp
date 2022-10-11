#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int A, B, C;
  int N;

  scanf("%d %d %d", &A, &B, &C);
  scanf("%d", &N);
  int a, b, c;
  int max_score = -1;

  for(int i=0; i<N; i++){
    int cur_score = 0;
    
    for(int k=0; k<3; k++){
	  scanf("%d %d %d", &a, &b, &c);
	  cur_score += (a*A + b*B + c*C);
	}

	if(max_score < cur_score)
	  max_score = cur_score;
  }

  printf("%d\n", max_score);

  return 0;
}
