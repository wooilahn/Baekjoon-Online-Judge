#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(){
  int N, L;
  scanf("%d %d", &N, &L);

  int num;
  for(int i=0; i<N; i++){ 
    scanf("%d", &num);
	v.push_back(num);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<N; i++){
    if(L >= v[i])
	  L++;
	else if(L < v[i])
	  break;
  }

  printf("%d\n", L);
  return 0;
}
