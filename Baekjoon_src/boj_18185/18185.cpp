#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10005] = {0};

int main(){
  int N, ans = 0;
  scanf("%d", &N);

  for(int i=1; i<=N; i++)
    scanf("%d", &arr[i]);

  for(int i=1; i<=N; i++){
    if(arr[i+1] > arr[i+2]){
	  int f = min(min(arr[i], arr[i+1]), arr[i+1]-arr[i+2]);
	  ans += f*5;
	  arr[i] -= f;
	  arr[i+1] -= f;

	  int s = min(min(arr[i], arr[i+1]), arr[i+2]);
	  ans += s*7;
	  arr[i] -= s;
	  arr[i+1] -= s;
	  arr[i+2] -= s;
	}
	else if(arr[i+1] <= arr[i+2]){
	  int s = min(min(arr[i], arr[i + 1]), arr[i + 2]);
	  ans += s*7;
	  arr[i] -= s;
	  arr[i+1] -= s;
	  arr[i+2] -= s;

	  int f = min(arr[i], arr[i+1]);
	  ans += f*5;
	  arr[i] -= f;
	  arr[i+1] -= f;
	}

	ans += arr[i] * 3;
  }

  printf("%d\n", ans);

  return 0;
}
