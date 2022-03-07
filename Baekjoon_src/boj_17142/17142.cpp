#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int map[55][55] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[55][55] = {0};

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  vector<pair<int,int>> virus;
  vector<pair<int,int>> wall;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	  
	  if(map[i][j] == 2)
	    virus.push_back(make_pair(i,j));
	  if(map[i][j] == 1)
	    wall.push_back(make_pair(i,j));
	}
  }

  vector<int> p_v(virus.size());

  for(int i=0; i<M; i++){
    p_v[p_v.size()-1-i] = 1;
  }

  int p_cnt = 0;
  int c_cnt = 0;
  int ans = 999999999;

  do {
    bool b_flag = false;
	int m_time = 0;
    p_cnt++;
    queue<pair<pair<int,int>, int>> q;
	memset(check, 0, sizeof(check));

	for(int i=0; i<p_v.size(); i++){
	  if(p_v[i] == 1)
	    q.push(make_pair(make_pair(virus[i].first, virus[i].second), 0));
	}

	for(int i=0; i<wall.size(); i++){ 
	  check[wall[i].first][wall[i].second] = true;
	}

	while(!q.empty()){
	  int cur_r = q.front().first.first;
	  int cur_c = q.front().first.second;
	  int cur_t = q.front().second;
	  q.pop();

	  if(check[cur_r][cur_c])
	    continue;
	  else
	    check[cur_r][cur_c] = true;
	  
	  if(map[cur_r][cur_c] != 2)
	    m_time = max(m_time, cur_t);

	  for(int i=0; i<4; i++){
	    int tmp_r = cur_r + dx[i];
		int tmp_c = cur_c + dy[i];
		int tmp_t = cur_t + 1;

		if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= N)
		  continue;
		else {
		  if(check[tmp_r][tmp_c])
		    continue;
		  
		  q.push(make_pair(make_pair(tmp_r, tmp_c), tmp_t));
		}
	  }
	}

	for(int i=0; i<N; i++){
	  for(int j=0; j<N; j++){
	    if(!check[i][j] && map[i][j] != 2){
		  c_cnt++;
		  b_flag = true;
		  break;
		}
	  }
	  if(b_flag == true)
	    break;
	}

	if(!b_flag)
	  ans = min(ans, m_time);
	
  } while(next_permutation(p_v.begin(), p_v.end()));

  if(p_cnt == c_cnt)
    printf("-1\n");
  else
    printf("%d\n", ans);

  return 0;
}
