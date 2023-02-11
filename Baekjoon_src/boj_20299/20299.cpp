#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main(){
  int N, K, L;
  scanf("%d %d %d", &N, &K, &L);

  int n_team = 0;

  while(N--){
    int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);

	if(n1+n2+n3 >= K){
	  if(n1 >= L && n2 >= L && n3 >= L){
	    v.push_back(n1);
		v.push_back(n2);
		v.push_back(n3);
		n_team++;
	  }
	}
  }

  printf("%d\n", n_team);

  for(int i=0; i<v.size(); i++)
    printf("%d ", v[i]);
  printf("\n");

  return 0;
}
