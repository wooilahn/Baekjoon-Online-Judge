#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main(){
  int N;
  scanf("%d", &N);

  int num;
  v.resize(N+3);

  for(int i=1; i<=N; i++){
    scanf("%d", &num);
	v[i] = num;
  }

  int A_sum = 0;

  for(int i=1; i<=N; i++){
    int cur_B = v[i]*i;

	printf("%d ", cur_B - A_sum);
	A_sum += (cur_B - A_sum);
  }
  printf("\n");

  return 0;
}
