#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[55][55] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pair<int, int>> air_cleaner;
vector<pair<int, int>> dust;

int main(){
  int R, C, T;
  scanf("%d %d %d", &R, &C, &T);

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
	  scanf("%d", &map[i][j]);

	  if(map[i][j] == -1)
	    air_cleaner.push_back(make_pair(i,j));
	}
  }

  int cur_time = 0;

  while(true){
    dust.clear();
	int tmp_map[55][55] = {0};
	queue<pair<int,int>> q;

	tmp_map[air_cleaner[0].first][air_cleaner[0].second] = -1;
	tmp_map[air_cleaner[1].first][air_cleaner[1].second] = -1;

    for(int i=0; i<R; i++){
	  for(int j=0; j<C; j++){
	    if(map[i][j] > 0)
		  q.push(make_pair(i, j));
	  }
	}

	// 확산
	while(!q.empty()){
	  int cur_r = q.front().first;
	  int cur_c = q.front().second;
	  int cur_dust = map[cur_r][cur_c];
	  q.pop();

	  int n_div = 0;

	  for(int i=0; i<4; i++){
	    int tmp_r = cur_r + dx[i];
		int tmp_c = cur_c + dy[i];

		if(tmp_r < 0 || tmp_r >= R || tmp_c < 0 || tmp_c >= C)
		  continue;
		if(tmp_map[tmp_r][tmp_c] == -1)
		  continue;

		tmp_map[tmp_r][tmp_c] += cur_dust / 5;
		n_div++;
	  }

	  tmp_map[cur_r][cur_c] += cur_dust - (cur_dust/5)*n_div;
	}

	for(int i=0; i<R; i++){
	  for(int j=0; j<C; j++){
	    map[i][j] = tmp_map[i][j];
	  }
	}

	// 공기청정기 작동
	// 윗 부분
	int up_r = air_cleaner[0].first;
	int up_c = air_cleaner[0].second;
	map[up_r-1][up_c] = 0;

	for(int i=up_r-1; i>0; i--)
	  map[i][up_c] = map[i-1][up_c];
	
	for(int i=0; i<C-1; i++)
	  map[0][i] = map[0][i+1];

	for(int i=0; i<=up_r-1; i++)
	  map[i][C-1] = map[i+1][C-1];

	for(int i=C-1; i>1; i--)
	  map[up_r][i] = map[up_r][i-1];

	map[up_r][up_c + 1] = 0;

	// 아랫 부분
	int down_r = air_cleaner[1].first;
	int down_c = air_cleaner[1].second;
	map[down_r+1][down_c] = 0;

	for(int i=down_r+1; i<R-1; i++)
	  map[i][down_c] = map[i+1][down_c];
	 
	for(int i=0; i<C-1; i++)
	  map[R-1][i] = map[R-1][i+1];

	for(int i=R-1; i>=down_r+1; i--)
	  map[i][C-1] = map[i-1][C-1];

	for(int i=C-1; i>1; i--)
	  map[down_r][i] = map[down_r][i-1];

	map[down_r][down_c+1] = 0;

    cur_time++;
	if(cur_time == T)
	  break;
  }

  // T초 후에 미세먼지의 양 출력
  int ans = 0;

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
	  if(map[i][j] > 0)
	    ans += map[i][j];
	}
  }

  printf("%d\n", ans);

  return 0;
}
