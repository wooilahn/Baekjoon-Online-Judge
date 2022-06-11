#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int map[55][55] = {0};
int tmp_map[55][55] = {0};

vector<int> d_v; // 방향 (위(r--), 아래(r++), 왼쪽(c--), 오른쪽(c++))
vector<int> s_v; // 거리 

int shark_r, shark_c;
int cur_d, cur_s;

int ans_marble1 = 0;
int ans_marble2 = 0;
int ans_marble3 = 0;

void copy_map(){

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  map[i][j] = tmp_map[i][j];
	}
  }

  return;
}

void do_blizard(){
	for (int s=1; s<=cur_s; s++) {
		if (cur_d == 1) { // 위(r--)
		    if(shark_r-s >= 1 && shark_r-s <= N)
				map[shark_r-s][shark_c] = 0;
		}
		else if (cur_d == 2) { // 아래(r++)
		    if(shark_r+s >= 1 && shark_r+s <= N)
				map[shark_r+s][shark_c] = 0;
		}
		else if (cur_d == 3) { // 왼쪽(c--)
		    if(shark_c-s >= 1 && shark_c-s <= N)
				map[shark_r][shark_c-s] = 0;
		}
		else if (cur_d == 4) { // 오른쪽(c++)
		    if(shark_c+s >= 1 && shark_c+s <= N)
				map[shark_r][shark_c+s] = 0;
		}
	}

  return;
}

void move_marble(){
  bool zero_find_flag = false;

  int zero_r = shark_r;
  int zero_c = shark_c;

  int next_r = shark_r;
  int next_c = shark_c;

  int zero_dir = 0; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
  int zero_move = 0;
  int zero_tar_move = 1;
  int zero_move_cnt = 0;

  int next_dir = 0; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
  int next_move = 0;
  int next_tar_move = 1;
  int next_move_cnt = 0;

  while(true){
    if(next_dir == 0) // 서(c--)
	  next_c--;
	else if(next_dir == 1) // 남(r++)
	  next_r++;
	else if(next_dir == 2)  // 동(c++)
	  next_c++;
	else if(next_dir == 3)  // 북(r--)
	  next_r--;

	next_move++;

	if (next_move == next_tar_move) {
		next_move = 0;
		next_move_cnt++;
		next_dir = (next_dir + 1) % 4;
	}
	if (next_move_cnt == 2) {
		next_move_cnt = 0;
		next_tar_move++;
	}

	if(zero_find_flag == false && map[next_r][next_c] == 0){
	  zero_find_flag = true;
	  zero_r = next_r;
	  zero_c = next_c;
	  
	  zero_dir = next_dir;
	  zero_move = next_move;
	  zero_tar_move = next_tar_move;
	  zero_move_cnt = next_move_cnt;
	}
	if(zero_find_flag == true && map[next_r][next_c] >= 1 && map[next_r][next_c] <= 3){
	  map[zero_r][zero_c] = map[next_r][next_c];
	  map[next_r][next_c] = 0;

	  while(map[zero_r][zero_c] != 0){
	    if(zero_dir == 0) // 서(c--)
		  zero_c--;
		else if(zero_dir == 1) // 남(r++)
		  zero_r++;
		else if(zero_dir == 2) // 동(c++)
		  zero_c++;
		else if(zero_dir == 3) // 북(r--)
		  zero_r--;
		  
		zero_move++;

		if(zero_move == zero_tar_move){
		  zero_move = 0;
		  zero_move_cnt++;
		  zero_dir = (zero_dir+1)%4;
		}
		if(zero_move_cnt == 2){
		  zero_move_cnt = 0;
		  zero_tar_move++;
		}
	  }
	}

	if (next_r == 1 && next_c == 1)
	  break;
  }

  return;
}

void bomb_marble(){
  while(true){
    int tmp_marble1 = 0;
	int tmp_marble2 = 0;
	int tmp_marble3 = 0;

	int bomb_r = shark_r;
	int bomb_c = shark_c;

	int start_r = shark_r;
	int start_c = shark_c;

	int target_num = -1;
	int target_cnt = 1;

	int bomb_dir = 0; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
	int bomb_move = 0;
	int bomb_tar_move = 1;
	int bomb_move_cnt = 0;

	int start_dir = 0; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
	int start_move = 0;
	int start_tar_move = 1;
	int start_move_cnt = 0;

	while(true){
	    int prev_r = bomb_r;
		int prev_c = bomb_c;

		if (bomb_dir == 0) // 서(c--)
			bomb_c--;
		else if (bomb_dir == 1) // 남(r++)
			bomb_r++;
		else if (bomb_dir == 2)  // 동(c++)
			bomb_c++;
		else if (bomb_dir == 3)  // 북(r--)
			bomb_r--;

		if(map[bomb_r][bomb_c] == map[prev_r][prev_c]){
		  target_cnt++;

		  if(target_num == -1){
		      target_num = map[prev_r][prev_c];
		      start_r = prev_r;
			  start_c = prev_c;

			  start_dir = bomb_dir; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
			  start_move = bomb_move;
			  start_tar_move = bomb_tar_move;
			  start_move_cnt = bomb_move_cnt;
		  }
		}
		else if(map[bomb_r][bomb_c] != map[prev_r][prev_c]){
		  if(target_cnt >= 4) { // 터트린다.
		    while(map[start_r][start_c] == target_num){
			  map[start_r][start_c] = 0;

			  if (start_dir == 0) // 서(c--)
				  start_c--;
			  else if (start_dir == 1) // 남(r++)
				  start_r++;
			  else if (start_dir == 2)  // 동(c++)
				  start_c++;
			  else if (start_dir == 3)  // 북(r--)
				  start_r--;

			  start_move++;

			  if (start_move == start_tar_move) {
				  start_move = 0;
				  start_move_cnt++;
				  start_dir = (start_dir + 1) % 4;
			  }
			  if (start_move_cnt == 2) {
				  start_move_cnt = 0;
				  start_tar_move++;
			  }
			}

			if(target_num == 1)
			  tmp_marble1 += target_cnt;
			else if(target_num == 2)
			  tmp_marble2 += target_cnt;
			else if(target_num == 3)
			  tmp_marble3 += target_cnt;
		  }

		  target_num = -1;
		  target_cnt = 1;
		}

		if (bomb_r <= 0 || bomb_r > N || bomb_c <= 0 || bomb_c > N)
			break;

		bomb_move++;

		if (bomb_move == bomb_tar_move) {
			bomb_move = 0;
			bomb_move_cnt++;
			bomb_dir = (bomb_dir + 1) % 4;
		}
		if (bomb_move_cnt == 2) {
			bomb_move_cnt = 0;
			bomb_tar_move++;
		}
	}

	if(tmp_marble1 == 0 && tmp_marble2 == 0 && tmp_marble3 == 0)
	  break;

	move_marble();

	ans_marble1 += tmp_marble1;
	ans_marble2 += tmp_marble2;
	ans_marble3 += tmp_marble3;
  }

  return;
}

// 구슬 추가 (그룹을 판단해서 [구슬의 갯수], [그룹을 이루고 있는 구슬의번호]를 차례대로 추가)
void add_marble(){
  memset(tmp_map, 0, sizeof(tmp_map));

  int group_r = shark_r;
  int group_c = shark_c-1;

  int copy_r = shark_r;
  int copy_c = shark_c-1;

  int target_num = map[group_r][group_c];
  int target_cnt = 1;
  int copy_cnt = 0;

  int group_dir = 1; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
  int group_move = 0;
  int group_tar_move = 1;
  int group_move_cnt = 1;

  int copy_dir = 1; // 0: 서(c--), 1: 남(r++), 2: 동(c++), 3: 북(r--)
  int copy_move = 0;
  int copy_tar_move = 1;
  int copy_move_cnt = 1;

  tmp_map[shark_r][shark_c] = 7;

  while(true){
	  int prev_r = group_r;
	  int prev_c = group_c;

	  if (group_dir == 0) // 서(c--)
		  group_c--;
	  else if (group_dir == 1) // 남(r++)
		  group_r++;
	  else if (group_dir == 2)  // 동(c++)
		  group_c++;
	  else if (group_dir == 3)  // 북(r--)
		  group_r--;

	  if(group_r <= 0 || group_r > N || group_c <= 0 || group_c > N)
	    break;

	  if (map[group_r][group_c] == map[prev_r][prev_c]) {
		  target_cnt++;
	  }
	  else if (map[group_r][group_c] != map[prev_r][prev_c]) {
	      if(copy_r <= 0 || copy_r > N || copy_c <= 0 || copy_c > N)
		    break;

		  while(true){
		      if(copy_cnt == 0)
				tmp_map[copy_r][copy_c] = target_cnt;
			  else if(copy_cnt == 1)
			    tmp_map[copy_r][copy_c] = target_num;

			  if (copy_dir == 0) // 서(c--)
				  copy_c--;
			  else if (copy_dir == 1) // 남(r++)
				  copy_r++;
			  else if (copy_dir == 2)  // 동(c++)
				  copy_c++;
			  else if (copy_dir == 3)  // 북(r--)
				  copy_r--;

			  copy_move++;

			  if (copy_move == copy_tar_move) {
				  copy_move = 0;
				  copy_move_cnt++;
				  copy_dir = (copy_dir + 1) % 4;
			  }
			  if (copy_move_cnt == 2) {
				  copy_move_cnt = 0;
				  copy_tar_move++;
			  }

			  copy_cnt++;

			  if(copy_cnt == 2){
			    copy_cnt = 0;
			    break;
			  }
		  }
		  target_num = map[group_r][group_c];
		  target_cnt = 1;
	  }

	  group_move++;

	  if (group_move == group_tar_move) {
		  group_move = 0;
		  group_move_cnt++;
		  group_dir = (group_dir + 1) % 4;
	  }
	  if (group_move_cnt == 2) {
		  group_move_cnt = 0;
		  group_tar_move++;
	  }
  }

  copy_map();
  return;
}

void solve(){
  shark_r = (N+1)/2;
  shark_c = (N+1)/2;
  map[shark_r][shark_c] = 7;

  for(int i=0; i<M; i++){
    cur_d = d_v[i];
	cur_s = s_v[i];

	// 블리자드 발동 (해당 방향의 구슬들 모두 제거)
	do_blizard();

	// 구슬을 움직임
	move_marble();

	// 연속된 4개 이상의 구슬들 폭파
	bomb_marble();

	// 구슬 추가 (그룹을 판단해서 [구슬의 갯수], [그룹을 이루고 있는 구슬의번호]를 차례대로 추가)
	add_marble();
  }

  printf("%d\n", 1*ans_marble1 + 2*ans_marble2 + 3*ans_marble3);
  return;
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){ 
	 scanf("%d", &map[i][j]);
	}
  }

  int di, si;
  for(int i=0; i<M; i++){
    scanf("%d %d", &di, &si);
	d_v.push_back(di);
	s_v.push_back(si);
  }

  solve();

  return 0;
}
