#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<int> v;
int visited[100005] = {0};
int done[100005] = {0};
int cnt;

void solve(int cur_idx){
  visited[cur_idx] = true;
  int next_idx = v[cur_idx];

  if(!visited[next_idx])
    solve(next_idx);
  else if(!done[next_idx]){
    for(int i=next_idx; i!=cur_idx; i=v[i])
	  cnt++;
	cnt++;
  }

  done[cur_idx] = true;
  return;
}

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int n, num;
	scanf("%d", &n);

	v.clear();
	v.resize(n+2);
	memset(visited, 0, sizeof(visited));
	memset(done, 0, sizeof(done));
	cnt = 0;

	for(int i=1; i<=n; i++){
	  scanf("%d", &num);
	  v[i] = num;

	  if(i == num){
	    cnt++;
		visited[i] = true;
		done[i] = true;
	  }
	}

	for(int i=1; i<=n; i++){
	  if(!visited[i]){
	    solve(i);
	  }
	}

	printf("%d\n", n-cnt);
  }

  return 0;
}
