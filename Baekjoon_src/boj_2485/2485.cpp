#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<int> dist;

int gcd(int a, int b){
  return b ? gcd(b, a%b) : a;
}

int main(){
  int N;
  int min = __INT_MAX__;
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    int num;
    scanf("%d", &num);
    arr.push_back(num);
  }

  for(int i=1; i<N; i++){
    dist.push_back(arr[i] - arr[i-1]);
  }

  for(int i=1; i<N-1; i++){
    int temp = gcd(dist[i-1], dist[i]);
    if(min > temp) min = temp;
  }

  int ans = 0;

  for(int i=0; i<N; i++){
    if(i+1 == N)
      break;
    if(arr[i+1] - arr[i] != min){
      int tmp = (arr[i+1] - arr[i])/min - 1;
      ans += tmp;
    }
  }

  printf("%d\n", ans);
  return 0;
}
