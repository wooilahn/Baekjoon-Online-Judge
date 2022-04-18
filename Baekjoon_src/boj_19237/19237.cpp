#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct shark{
  int num;
  int live; // -1: dead, 1: smell, 2: live
  int dir;
  int cnt;
  int r;
  int c;
};

int N, M, k;
int map[25][25];

vector<shark> sh_map[25][25];
vector<shark> copy_map[25][25];
vector<int> sh_dir[650][7];
shark sh_pos[650];

void CopyMap(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  sh_map[i][j].clear();

	  for(int idx=0; idx<copy_map[i][j].size(); idx++){
	    if(copy_map[i][j].at(idx).live > 0)
			sh_map[i][j].push_back(copy_map[i][j].at(idx));
	  }
	  
	  copy_map[i][j].clear();
	}
  }

  return;
}

int CheckShark(){
  int check_shark_num = 0;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  for(int idx=0; idx<sh_map[i][j].size(); idx++){
	    if(sh_map[i][j].at(idx).live == 2 && sh_map[i][j].at(idx).num > 0)
			check_shark_num++;
	  }
	}
  }

  return check_shark_num;
}

void solve(){
  int cur_time = 0;

  while(true){
    int n_shark = CheckShark();
	if(n_shark == 1){
	  printf("%d\n", cur_time);
	  return;
	}

	cur_time++;
	if(cur_time > 1000)
	 break;

	shark smell_shark;
	shark new_smell_shark;

	// 1. 냄새의 count 1씩 감소
	for(int r=0; r<N; r++){
	  for(int c=0; c<N; c++){
	    for(int idx=0; idx<sh_map[r][c].size(); idx++){
		  if(sh_map[r][c].at(idx).live == 1){ // from 'smell' state
            if(sh_map[r][c].at(idx).cnt <= 1){
			  sh_map[r][c].at(idx).live = -1; // to 'dead' state
			  continue;
			}

		    smell_shark = sh_map[r][c].at(idx);
			sh_map[r][c].at(idx).cnt--;
			smell_shark.cnt--;
			copy_map[r][c].push_back(smell_shark);
		  }
		}
	  }
	}

	// 2. 'live' state 이면 자신의 자리에 smell 남김
	for(int i=1; i<=M; i++){
	  if(sh_pos[i].live == 2){ 
	    new_smell_shark = {i, 1, 0, k, sh_pos[i].r, sh_pos[i].c};  // num, live, dir, cnt, r, c
		copy_map[sh_pos[i].r][sh_pos[i].c].push_back(new_smell_shark);
	  }
	}

	// 3. 각 상어를 이동
	for(int i=1; i<=M; i++){
	  if(sh_pos[i].live == 2){
	    int cur_r = sh_pos[i].r;
		int cur_c = sh_pos[i].c;
		int cur_dir = sh_pos[i].dir;
		int tmp_r, tmp_c;

		bool move_flag = false;
		for(int d=0; d<4; d++){
		  if(sh_dir[i][cur_dir][d] == 1){ // up (r--)
		    tmp_r = cur_r - 1;
			tmp_c = cur_c;
		  }
		  else if(sh_dir[i][cur_dir][d] == 2){ // down (r++)
		    tmp_r = cur_r + 1;
			tmp_c = cur_c;
		  }
		  else if(sh_dir[i][cur_dir][d] == 3){ // left (c--)
		    tmp_r = cur_r;
			tmp_c = cur_c - 1;
		  }
		  else if(sh_dir[i][cur_dir][d] == 4){ // right (c++)
		    tmp_r = cur_r;
			tmp_c = cur_c + 1;
		  }

		  if(tmp_r < 0 || tmp_c < 0 || tmp_r >= N || tmp_c >= N)
		    continue;

		  int n_idx = 0;

		  // 3-(1): 냄새가 없는 칸으로 이동 (뭐가 있는 경우)
		  for(int idx=0; idx<copy_map[tmp_r][tmp_c].size(); idx++){
		    shark copy_sh = copy_map[tmp_r][tmp_c].at(idx);

			if(copy_sh.live == 1) // 냄새가 있는 경우
			  break;
			else if(copy_sh.live == 2){ // 살아있는 경우
			  if(copy_sh.num < sh_pos[i].num){ // 잡아먹히는 경우
				sh_pos[i].live = -1;
				sh_pos[i].cnt = 0;
				move_flag = true;
				break;
			  }
			  else if(copy_sh.num > sh_pos[i].num){ // 잡아먹는 경우
				// 잡아먹기
				copy_map[tmp_r][tmp_c].at(idx).live = -1; 
				copy_map[tmp_r][tmp_c].at(idx).cnt = 0;
				sh_pos[copy_map[tmp_r][tmp_c].at(idx).num].live = -1;
				sh_pos[copy_map[tmp_r][tmp_c].at(idx).num].cnt = 0;
				// winner 이동
				shark winner_sh = {i, 2, sh_dir[i][cur_dir][d], k, tmp_r, tmp_c}; // num, live, dir, cnt, r, c
				copy_map[tmp_r][tmp_c].push_back(winner_sh);
				sh_pos[i].r = tmp_r;
				sh_pos[i].c = tmp_c;
				sh_pos[i].dir = sh_dir[i][cur_dir][d];
				move_flag = true;
				break;
			  }
			}
			n_idx++;
		  }

		  if (move_flag)
			  break;

		  // 3-(2): 아무 냄새가 없는 칸으로 이동 (아예 없는 경우)
		  if (copy_map[tmp_r][tmp_c].size() == n_idx) {
			  shark new_move_sh = {i, 2, sh_dir[i][cur_dir][d], k, tmp_r, tmp_c}; // num, live, dir, cnt, r, c
			  copy_map[tmp_r][tmp_c].push_back(new_move_sh);
			  sh_pos[i].r = tmp_r;
			  sh_pos[i].c = tmp_c;
			  sh_pos[i].dir = sh_dir[i][cur_dir][d];
			  move_flag = true;
			  break;
		  }

		  if (move_flag)
			  break;
		}

		// 3-(3): 만약 move 못했다면, 자기 냄새가 있는 칸으로 이동
		if(!move_flag){
		  int d_n = 0;
		  for(int d=0; d<4; d++){
		      d_n++;

			  if (sh_dir[i][cur_dir][d] == 1) { // up (r--)
				  tmp_r = cur_r - 1;
				  tmp_c = cur_c;
			  }
			  else if (sh_dir[i][cur_dir][d] == 2) { // down (r++)
				  tmp_r = cur_r + 1;
				  tmp_c = cur_c;
			  }
			  else if (sh_dir[i][cur_dir][d] == 3) { // left (c--)
				  tmp_r = cur_r;
				  tmp_c = cur_c - 1;
			  }
			  else if (sh_dir[i][cur_dir][d] == 4) { // right (c++)
				  tmp_r = cur_r;
				  tmp_c = cur_c + 1;
			  }

			  if (tmp_r < 0 || tmp_c < 0 || tmp_r >= N || tmp_c >= N)
				  continue;

			  for(int idx=0; idx<copy_map[tmp_r][tmp_c].size(); idx++){
			    shark tmp_smell_shark = copy_map[tmp_r][tmp_c].at(idx);

				if(tmp_smell_shark.live == 1 && tmp_smell_shark.num == i){ // 자기 smell 찾은 경우
				  shark last_move_sh = {i, 2, sh_dir[i][cur_dir][d], k, tmp_r, tmp_c};  // num, live, dir, cnt, r, c
				  copy_map[tmp_r][tmp_c].push_back(last_move_sh);
				  sh_pos[i].r = tmp_r;
				  sh_pos[i].c = tmp_c;
				  sh_pos[i].dir = sh_dir[i][cur_dir][d];
				  move_flag = true;
				  break;
				}
			  }

			  if(move_flag)
			    break;
		  }
		}
	  }
	}

	// CopyMap (from 'copy_map' to 'sh_map')
	CopyMap();
  }

  printf("-1\n");
  return;
}

void get_input(){
  scanf("%d %d %d", &N, &M, &k);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);

	  if(map[i][j] > 0){
	    int sh_num = map[i][j];
		shark sh = {sh_num, 2, 0, 0, i, j}; // num, live, dir, cnt, r, c
		sh_map[i][j].push_back(sh);
		sh_pos[sh_num] = sh;
	  }
	}
  }

  int tmp_dir = 0;
  for(int i=1; i<=M; i++){
    scanf("%d", &tmp_dir);
	sh_pos[i].dir = tmp_dir;
	sh_map[sh_pos[i].r][sh_pos[i].c].at(0).dir = tmp_dir;
  }

  int next_dir = 0;
  for(int i=1; i<=M; i++){
    for(int d=1; d<=4; d++){
	  for(int idx=0; idx<4; idx++){
		  scanf("%d", &next_dir);
		  sh_dir[i][d].push_back(next_dir);
	  }
	}
  }

  return;
}

int main(){
  get_input();
  solve();

  return 0;
}
