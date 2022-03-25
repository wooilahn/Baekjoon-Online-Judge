#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) a > b ? a : b;

using namespace std;

int main(){

  int ans_candidate = 0;
  int ans_score = 0;

  int n1, n2, n3, n4;

  for(int i=1; i<=5; i++){
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
	int total_score = n1 + n2 + n3 + n4;
	
	if(ans_score < total_score){
	  ans_score = total_score;
	  ans_candidate = i;
	}
  }

  printf("%d %d\n", ans_candidate, ans_score);

  return 0;
}
