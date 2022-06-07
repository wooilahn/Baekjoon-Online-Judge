#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, Q, IR, IC;
vector<int> levels;

int sub_R, sub_C, num_R, num_C;
int remain_ice = 0;
int biggest_ice = 0;

int ice_map[70][70] = {0};
int tmp_map[70][70] = {0};
int reduce_map[70][70] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void calculate_map(){
  queue<pair<int,int>> q;
  bool check[70][70] = {0};

  for(int i=0; i<IR; i++){
    for(int j=0; j<IC; j++){
	  remain_ice += max(0, ice_map[i][j]);

	  if(check[i][j] || ice_map[i][j] <= 0)
	    continue;
	  else {
	    int cur_ice = 0;
	    q.push(make_pair(i,j));
		
		while(!q.empty()){
		  int cur_r = q.front().first;
		  int cur_c = q.front().second;
		  q.pop();

		  if(check[cur_r][cur_c])
		    continue;
	      else {
		    check[cur_r][cur_c] = true;
			cur_ice++;
		  }

		  for(int k=0; k<4; k++){
		    int tmp_r = cur_r + dx[k];
			int tmp_c = cur_c + dy[k];

			if(tmp_r < 0 || tmp_r >= IR || tmp_c < 0 || tmp_c >= IC)
			  continue;
			if(check[tmp_r][tmp_c])
			  continue;
			if(ice_map[tmp_r][tmp_c] <= 0)
			  continue;

			q.push(make_pair(tmp_r, tmp_c));
		  }
		}

		biggest_ice = max(cur_ice, biggest_ice);
	  }
	}
  }

  printf("%d\n%d\n", remain_ice, biggest_ice);
}

void move_ice(){
  // column와 row을 바꾼다. 
  num_R = IR / sub_R;
  num_C = IC / sub_C;

  for(int i=0; i<num_R; i++){
    for(int j=0; j<num_C; j++){
	  // 90 rotation start point
	  int start_R = i*sub_R;
	  int start_C = j*sub_C;

	  for(int r=0; r<sub_R; r++){
	    for(int c=0; c<sub_C; c++){
		  tmp_map[start_R+c][start_C+sub_C-1-r] = ice_map[start_R+r][start_C+c];
		}
	  }
	}
  }

  return;
}

void copy_map(){
  for(int i=0; i<IR; i++){
    for(int j=0; j<IC; j++){
	  ice_map[i][j] = tmp_map[i][j];
	}
  }
  return;
}

void reduce_ice(){
  memset(reduce_map, 0, sizeof(reduce_map));

  for(int i=0; i<IR; i++){
    for(int j=0; j<IC; j++){
	  int connect_ice = 0;

	  for(int k=0; k<4; k++){
	    int tmp_r = i+dx[k];
		int tmp_c = j+dy[k];

		if(tmp_r < 0 || tmp_r >= IR || tmp_c < 0 || tmp_c >= IC) 
		  continue;

		if(ice_map[tmp_r][tmp_c] > 0)
		  connect_ice++;
	  }

	  if(connect_ice <= 2)
	    reduce_map[i][j] = max(ice_map[i][j]-1, 0);
	  else
	    reduce_map[i][j] = ice_map[i][j];
	}
  }

  for(int i=0; i<IR; i++){
    for(int j=0; j<IC; j++){
	  ice_map[i][j] = reduce_map[i][j];
	}
  }
}

void solve(){
  for(int idx=0; idx<levels.size(); idx++){
    int level = levels[idx];

    // 90도 회전
	memset(tmp_map, 0, sizeof(tmp_map));
	sub_R = int(pow(2, level));
	sub_C = int(pow(2, level));
	move_ice();
	copy_map();

	// 얼음크기 줄이기
	reduce_ice();
  }

  calculate_map();
  return;
}

int main(){
  scanf("%d %d", &N, &Q);
  
  IR = int(pow(2, N));
  IC = int(pow(2, N));

  for(int i=0; i<IR; i++)
    for(int j=0; j<IC; j++)
	  scanf("%d", &ice_map[i][j]);
  
  for(int i=0; i<Q; i++){
    int num;
	scanf("%d", &num);
	levels.push_back(num);
  }
  
  solve();

  return 0;
}

