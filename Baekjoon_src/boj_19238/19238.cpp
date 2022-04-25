#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, gas;
int t_r, t_c;
int map[25][25] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check[25][25] = {0};
bool person_check[500] = {0};
vector<pair<int,int>> src_v;
vector<pair<int,int>> dst_v;

void solve(){
  int arrive_n = 0;

  while(arrive_n < M){
    int person_idx = -1;
	int person_r = 999, person_c = 999;
	int person_dist = 99999999;
	int consumed_gas = 0;
	memset(check, 0, sizeof(check));

	// t_r, t_c로부터 각 승객 거리 계산
	queue<pair<pair<int,int> ,int>> q;
	q.push(make_pair(make_pair(t_r, t_c), 0));

	while(!q.empty()){
	  int cur_r = q.front().first.first;
	  int cur_c = q.front().first.second;
	  int cur_dist = q.front().second;
	  q.pop();

	  if(check[cur_r][cur_c])
		  continue;
	  else
	     check[cur_r][cur_c] = true;

	  for(int i=0; i<M; i++){
	    if(person_check[i])
		  continue;

		if(src_v[i].first == cur_r && src_v[i].second == cur_c){
		  if(person_dist > cur_dist){
		    person_idx = i;
		    person_r = cur_r;
			person_c = cur_c;
			person_dist = cur_dist;
		  }
		  else if(person_dist == cur_dist){
		    if(person_r > cur_r){
			  person_idx = i;
			  person_r = cur_r;
			  person_c = cur_c;
			  person_dist = cur_dist;
			}
			else if(person_r == cur_r){
			  if(person_c > cur_c){
			    person_idx = i;
				person_r = cur_r;
				person_c = cur_c;
				person_dist = cur_dist;
			  }
			}
		  }
		}
	  }

	  for(int i=0; i<4; i++){
	    int tmp_r = cur_r + dx[i];
		int tmp_c = cur_c + dy[i];

		if(tmp_r < 0 || tmp_c < 0 || tmp_r >= N || tmp_c >= N)
		  continue;
		if(map[tmp_r][tmp_c] == 1)
		  continue;

		q.push(make_pair(make_pair(tmp_r,tmp_c), cur_dist+1));
	  }
	}

	// 벽에 가로막혀 person을 못찾은 경우 (return -1)
	if(person_idx == -1){
	  printf("-1\n");
	  return;
	}

	// consumed_gas = 승객 태우는 데 소모되는 연료양 + 목적지 가는데 소모되는 연료양
	queue<pair<pair<int,int>, int>> taxi_q;
	int taxi_map[25][25] = {0};
	taxi_q.push(make_pair(make_pair(person_r, person_c), 0));

	int taxi_dst_r = dst_v[person_idx].first;
	int taxi_dst_c = dst_v[person_idx].second;
	int taxi_dst_dist = 99999999;

	while(!taxi_q.empty()){
	  int t_cur_r = taxi_q.front().first.first;
	  int t_cur_c = taxi_q.front().first.second;
	  int t_cur_dist = taxi_q.front().second;
	  taxi_q.pop();

	  if(taxi_map[t_cur_r][t_cur_c])
	    continue;
	  else
	    taxi_map[t_cur_r][t_cur_c] = true;

	  if(t_cur_r == taxi_dst_r && t_cur_c == taxi_dst_c)
	    taxi_dst_dist = min(taxi_dst_dist, t_cur_dist);
	  
	  for(int i=0; i<4; i++){
	    int t_tmp_r = t_cur_r + dx[i];
		int t_tmp_c = t_cur_c + dy[i];

		if(t_tmp_r < 0 || t_tmp_c < 0 || t_tmp_r >= N || t_tmp_c >= N)
		  continue;
		if(map[t_tmp_r][t_tmp_c] == 1)
		  continue;

		taxi_q.push(make_pair(make_pair(t_tmp_r, t_tmp_c), t_cur_dist+1));
	  }
	}

	// 기름이 모자란 경우 (return -1)
	consumed_gas = person_dist + taxi_dst_dist;

	if(consumed_gas > gas){
	  printf("-1\n");
	  return;
	}
	else
	  gas -= consumed_gas;

	// (t_r,t_c)를 dst[person_idx]로 바꾸고, (consumer_gas * 2)만큼 연료충전
	t_r = taxi_dst_r;
	t_c = taxi_dst_c;
	gas += taxi_dst_dist * 2;

	// 태운 승객 true, 태운 횟수 1증가
	person_check[person_idx] = true;
    arrive_n++;
  }

  printf("%d\n", gas);
  return;
}

void init(){
  scanf("%d %d %d", &N, &M, &gas);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  scanf("%d %d", &t_r, &t_c);
  t_r -= 1;
  t_c -= 1;
  int s_r, s_c, d_r, d_c;

  for(int i=0; i<M; i++){
    scanf("%d %d %d %d", &s_r, &s_c, &d_r, &d_c);
	src_v.push_back(make_pair(s_r-1, s_c-1));
	dst_v.push_back(make_pair(d_r-1, d_c-1));
  }

  return;
}

int main(){
  init();
  solve();
  return 0;
}
