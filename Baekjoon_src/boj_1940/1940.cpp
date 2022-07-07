#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  vector<int> v;

  for(int i=0; i<N; i++){
    int num;
	scanf("%d", &num);
	v.push_back(num);
  }

  int answer = 0;

  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
	  if(v[i] + v[j] == M)
	    answer++;
	}
  }
  
  printf("%d\n", answer);

  return 0;
}
