#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>

using namespace std;

deque<int> v;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  int tmp_N = N;
  while(tmp_N != 0){
    v.push_front(tmp_N % 10);
	tmp_N /= 10;
  }

  int print_N;
  if(v.size()*N > M)
    print_N = M;
  else
    print_N = v.size()*N;

  for(int i=0; i<print_N; i++)
    printf("%d", v[i%v.size()]);
  printf("\n");
  
  return 0;
}
