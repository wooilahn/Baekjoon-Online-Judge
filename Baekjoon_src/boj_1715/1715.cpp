#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int> pq;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    int num;
    scanf("%d", &num);
    pq.push(-num);
  }

  if(pq.size() == 1){
    printf("0\n");
    pq.pop();
    return 0;
  }

  int ans = 0;

  while(!pq.empty()){
    if(pq.size() == 1)
      break;

    int n1 = -pq.top();
    pq.pop();

    int n2 = -pq.top();
    pq.pop();

    int tmp = n1+n2;
    ans += tmp;
    pq.push(-tmp);
  }

  printf("%d\n", ans);
  return 0;
}
