#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int,int>> v;
int visited[1010] = {0};
int matched[1010] = {0};

bool bm(int idx){
  for(int i=v[idx].first; i<=v[idx].second; i++){
    
	if(visited[i])
	  continue;
	
	visited[i] = true;

	if(matched[i] == 0 || bm(matched[i])){
	  matched[i] = idx;
	  return true;
	}
  }

  return false;
}

int main(){
  int T, N, M;
  int a, b;
  scanf("%d", &T);

  while(T--){
    scanf("%d %d", &N, &M);

	memset(visited, 0, sizeof(visited));
	memset(matched, 0, sizeof(matched));

	v.clear();
	v.push_back(make_pair(0, 0));

	for(int i=0; i<M; i++){
	  scanf("%d %d", &a, &b);
	  v.push_back(make_pair(a, b));
	}

	int ans = 0;

	for(int i=1; i<=M; i++){
	  memset(visited, 0, sizeof(visited));

	  if(bm(i))
	    ans++;
	}

	printf("%d\n", ans);
  }

  return 0;
}
