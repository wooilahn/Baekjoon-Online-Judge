#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  for(int i=0; i<M; i++){
    int num;
	scanf("%d", &num);
	v.push_back(num);
  }

  int ans = 0;

  for(int i=1; i<=N; i++){
    for(int k=0; k<v.size(); k++){
	  if(i % v[k] == 0){
	    ans += i;
		break;
	  }
	}
  }

  printf("%d\n", ans);
  return 0;
}
