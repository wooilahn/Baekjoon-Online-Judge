#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef long long ll;
ll arr[55] = {0};

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; i++)
    scanf("%lld",&arr[i]);
  
  bool flag = false;

  if(arr[1]-arr[0] == arr[2]-arr[1])
    flag = true;
  else if(arr[1]/arr[0] == arr[2]/arr[1])
    flag = false;

  if(flag)
    printf("%lld\n", arr[N-1] + (arr[1]-arr[0]));
  else if(!flag)
    printf("%lld\n", arr[N-1] * (arr[1]/arr[0]));
  
  return 0;
}
