#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(){

  v.resize(1003);

  v[1] = 1;

  for(int i=2; i<=1000; i++){
    int start_idx = (((i-1) * i) / 2) + 1;

	if(start_idx > 1000)
	  break;

    for(int k=start_idx; k<start_idx+i; k++){
	  if(k > 1000)
	    break;

	  v[k] = i;
	}
  }


  int A, B;
  int answer = 0;
  scanf("%d %d", &A, &B);

  for(int i=A; i<=B; i++){
    answer += v[i];
  }

  printf("%d\n", answer);

  return 0;
}
