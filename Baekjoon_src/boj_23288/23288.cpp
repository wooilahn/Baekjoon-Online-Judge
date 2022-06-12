#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int cur_dir = 0;
int cur_r = 1;
int cur_c = 1;

int map[25][25] = {0};
int dice[6] = {2, 4, 1, 3, 5, 6}; // 뒤(0), 왼쪽(1), 위(2), 오른쪽(3), 앞(4), 아래(5)

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void roll_dice(){ // dir: 0(동), 1(서), 2(남), 3(북)
  int tmp_dice[6] = {0};
  int tmp_r = cur_r;
  int tmp_c = cur_c;

  if(cur_dir == 0){      // 0(동) c++
    tmp_c++;

	if(tmp_c > M){
	  tmp_c = cur_c - 1;
	  cur_dir = 1;
	}
  }
  else if(cur_dir == 1){ // 1(서) c--
    tmp_c--;

	if(tmp_c <= 0){
	  tmp_c = cur_c + 1;
	  cur_dir = 0;
	}
  }
  else if(cur_dir == 2){ // 2(남) r++
    tmp_r++;

	if(tmp_r > N){
	  tmp_r = cur_r - 1;
	  cur_dir = 3;
	}
  }
  else if(cur_dir == 3){ // 3(북) r--
    tmp_r--;

	if(tmp_r <= 0){
	  tmp_r = cur_r + 1;
	  cur_dir = 2;
	}
  }

  cur_r = tmp_r;
  cur_c = tmp_c;

  // 뒤(0), 왼쪽(1), 위(2), 오른쪽(3), 앞(4), 아래(5)
  if(cur_dir == 0){ // 0(동)
    tmp_dice[0] = dice[0]; // 뒤 -> 뒤
    tmp_dice[1] = dice[5]; // 아래 -> 왼쪽
    tmp_dice[2] = dice[1]; // 왼쪽 -> 위
    tmp_dice[3] = dice[2]; // 위 -> 오른쪽
    tmp_dice[4] = dice[4]; // 앞 -> 앞
    tmp_dice[5] = dice[3]; // 오른쪽 -> 아래
  }
  else if(cur_dir == 1){ // 1(서)
	tmp_dice[0] = dice[0]; // 뒤 -> 뒤
	tmp_dice[1] = dice[2]; // 위 -> 왼쪽
	tmp_dice[2] = dice[3]; // 오른쪽 -> 위
	tmp_dice[3] = dice[5]; // 아래 -> 오른쪽
	tmp_dice[4] = dice[4]; // 앞 -> 앞
	tmp_dice[5] = dice[1]; // 왼쪽 -> 아래
  }
  else if(cur_dir == 2){ // 2(남)
    tmp_dice[0] = dice[5]; // 아래 -> 뒤
	tmp_dice[1] = dice[1]; // 왼쪽 -> 왼쪽
	tmp_dice[2] = dice[0]; // 뒤 -> 위
	tmp_dice[3] = dice[3]; // 오른쪽 -> 오른쪽
	tmp_dice[4] = dice[2]; // 위 -> 앞
	tmp_dice[5] = dice[4]; // 앞 -> 아래
  }
  else if(cur_dir == 3){ // 3(북)
    tmp_dice[0] = dice[2]; // 위 -> 뒤
	tmp_dice[1] = dice[1]; // 왼쪽 -> 왼쪽
	tmp_dice[2] = dice[4]; // 앞 -> 위
	tmp_dice[3] = dice[3]; // 오른쪽 -> 오른쪽
	tmp_dice[4] = dice[5]; // 아래 -> 앞
	tmp_dice[5] = dice[0]; // 뒤 -> 아래
  }

  for(int i=0; i<6; i++)
    dice[i] = tmp_dice[i];

  return;
}

void get_score(){
  queue<pair<int,int>> q;
  q.push(make_pair(cur_r, cur_c));
  int check[25][25] = {0};
  int n_c = 0;

  while(!q.empty()){
    int q_r = q.front().first;
	int q_c = q.front().second;
	q.pop();

	if(check[q_r][q_c])
	  continue;
	else {
	  n_c++;
	  check[q_r][q_c] = 1;
	 }

	for(int k=0; k<4; k++){
	  int tmp_r = q_r + dx[k];
	  int tmp_c = q_c + dy[k];

	  if(tmp_r <= 0 || tmp_r > N || tmp_c <= 0 || tmp_c > M)
	    continue;
	  if(map[tmp_r][tmp_c] == map[cur_r][cur_c])
	    q.push(make_pair(tmp_r, tmp_c));
	}
  }

  ans += map[cur_r][cur_c] * n_c;
  return;
}

void change_direction(){
  int A = dice[5];
  int B = map[cur_r][cur_c];

  if(A > B){ // 시계 방향 90도  (동0, 서1, 남2, 북3)
    if(cur_dir == 0)
	  cur_dir = 2;
	else if(cur_dir == 1)
	  cur_dir = 3;
	else if(cur_dir == 2)
	  cur_dir = 1;
	else if(cur_dir == 3)
	  cur_dir = 0;
  }
  else if(A < B){ // 반시계 방향 90도
    if(cur_dir == 0)
	  cur_dir = 3;
	else if(cur_dir == 1)
	  cur_dir = 2;
	else if(cur_dir == 2)
	  cur_dir = 0;
	else if(cur_dir == 3)
	  cur_dir = 1;
  }

  return;
}

void solve(){
  int trial_k = K;

  while(trial_k--){
    // 주사위를 굴린다.
    roll_dice();

	// 점수를 획득한다.
	get_score();

	// 이동방향을 바꾼다.
	change_direction();
  }
  printf("%d\n", ans);
  return;
}

int main(){
  scanf("%d %d %d", &N, &M, &K);

  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){ 
	  scanf("%d", &map[i][j]);
	}
  }

  solve();

  return 0;
}
