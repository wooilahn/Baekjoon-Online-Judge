#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, L, R;
int map[55][55] = {0};
int c_map[55][55] = {0};
bool check[55][55] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = 0;

bool check_arrays(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  if(map[i][j] != c_map[i][j])
	    return false;
	}
  }

  return true;
}

void copyMap(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  map[i][j] = c_map[i][j];
	}
  }

  return;
}

void solve(int cnt){
  ans = max(ans, cnt);
  memset(check, 0, sizeof(check));
  memset(c_map, -1, sizeof(c_map));

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  if(check[i][j])
	    continue;

	  queue<pair<int,int>> q;
	  vector<pair<int,int>> v;

	  q.push(make_pair(i,j));

	  while(!q.empty()){
	    int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if(check[cur_x][cur_y])
		  continue;
		else
		  check[cur_x][cur_y] = true;

		v.push_back(make_pair(cur_x, cur_y));

		for(int k=0; k<4; k++){
		  int tmp_x = cur_x + dx[k];
		  int tmp_y = cur_y + dy[k];

		  if(tmp_x < 0 || tmp_y < 0 || tmp_x >= N || tmp_y >= N)
		    continue;
		  if(check[tmp_x][tmp_y])
		    continue;

		  int diff_n = abs(map[tmp_x][tmp_y] - map[cur_x][cur_y]);
		  
		  if(diff_n >= L && diff_n <= R){
		    q.push(make_pair(tmp_x, tmp_y));

		  }
		}
	  }

	  double sum = 0;
	  for(int k=0; k<v.size(); k++){
	    sum += map[v[k].first][v[k].second];
	  }
	  sum /= v.size();

	  for(int k=0; k<v.size(); k++)
	    c_map[v[k].first][v[k].second] = (int)sum;
	}
  }

  bool flag = check_arrays();
  if (!flag){
      copyMap();
	  solve(cnt+1);
  }
  else
	  return;

  return;
}

int main(){
  scanf("%d %d %d", &N, &L, &R);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  solve(0);
  printf("%d\n", ans);

  return 0;
}
