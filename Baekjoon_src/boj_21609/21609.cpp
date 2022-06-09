#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
queue<pair<int, int>> s_q;

int N, M;
int ans = 0;

int b_r = -1;       // 기준블록의 r
int b_c = -1;       // 기준블록의 c
int b_size = -1;    // 블록그룹의 크기
int b_rainbow = -1; // 무지개 블록의 갯수
int b_normal = -1;  // 일반색 블록의 갯수

int map[25][25] = {0}; // -2: 빈칸, -1: 검은색블록, 0:무지개 블록, 1~M: 일반색 블록
int tmp_map[25][25] = {0};

bool check[25][25] = { 0 };
bool sq_check[25][25] = { 0 };
bool tmp_check[25][25] = { 0 };
bool block_check[25][25] = { 0 };

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


bool find_maxblock(){
  b_r = -1;
  b_c = -1;
  b_size = -1;
  b_rainbow = -1;
  b_normal = -1;

  memset(check, 0, sizeof(check));
  memset(block_check, 0, sizeof(block_check));
  memset(tmp_check, 0, sizeof(tmp_check));

  // 블록 그룹을 찾는다.
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  if(map[i][j] == -2 || map[i][j] == -1 || map[i][j] == 0) //빈 블록이거나 검은색블록이거나 무지개색 블록이면 continue
	    continue;

	  q.push(make_pair(i,j));
	  memset(check, 0, sizeof(check));
	  memset(tmp_check, 0, sizeof(tmp_check));
	  int t_r = i;
	  int t_c = j;
	  int t_size = 0;
	  int t_rainbow = 0;
	  int t_normal = 0;
	  int cur_color = map[i][j];
	  
	  while(!q.empty()){
	    int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		if(cur_color > 0 && map[cur_r][cur_c] > 0 && cur_color != map[cur_r][cur_c])
		  continue;
		if(check[cur_r][cur_c])
		  continue;
		else{
		  check[cur_r][cur_c] = true;
		  t_size++;

		  if(map[cur_r][cur_c] == 0) // 무지개색 블록이면
		    t_rainbow++; 
		  else if(map[cur_r][cur_c] == cur_color) // 일반색 블록이면
		    t_normal++;
		}
		tmp_check[cur_r][cur_c] = true;

		if(map[cur_r][cur_c] > 0 && map[cur_r][cur_c] == cur_color){
		  if(t_r > cur_r){
		    t_r = cur_r;
		    t_c = cur_c;
		  }
		  else if(t_r == cur_r){
		    if(t_c > cur_c){
		      t_r = cur_r;
			  t_c = cur_c;
		    }
		  }
		}

		for(int k=0; k<4; k++){
		  int tmp_r = cur_r + dx[k];
		  int tmp_c = cur_c + dy[k];

		  if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= N)
		    continue;
		  if(check[tmp_r][tmp_c])
		    continue;
		  if(map[tmp_r][tmp_c] == 0 || map[tmp_r][tmp_c] == cur_color)
		    q.push(make_pair(tmp_r, tmp_c));
		}
	  }

	  if(t_size >= 2 && b_size < t_size){ // 크기가 가장 큰 블록그룹
	    b_r = t_r;
		b_c = t_c;
		b_size = t_size;
		b_rainbow = t_rainbow;
		b_normal = t_normal;

		for(int tr=0; tr<N; tr++){
		  for(int tc=0; tc<N; tc++){
		    block_check[tr][tc] = tmp_check[tr][tc];
		  }
		}
	  }
	  if(t_size >= 2 && b_size == t_size){ 
	    if(b_rainbow < t_rainbow){ // 무지개 색 블록이면 더 많은 그룹
		  b_r = t_r;
		  b_c = t_c;
		  b_size = t_size;
		  b_rainbow = t_rainbow;
		  b_normal = t_normal;

		  for (int tr = 0; tr < N; tr++) {
			  for (int tc = 0; tc < N; tc++) {
				  block_check[tr][tc] = tmp_check[tr][tc];
			  }
		  }
		}
		else if(b_rainbow == t_rainbow){
		  if(b_r < t_r){ // 기준 블록의 행이 가장 큰 것
		    b_r = t_r;
			b_c = t_c;
			b_size = t_size;
			b_rainbow = t_rainbow;
			b_normal = t_normal;

			for (int tr = 0; tr < N; tr++) {
				for (int tc = 0; tc < N; tc++) {
					block_check[tr][tc] = tmp_check[tr][tc];
				}
			}
		  }
		  else if(b_r == t_r){
		    if(b_c < t_c){ // 기준 블록의 열이 가장 큰 것
			  b_r = t_r;
			  b_c = t_c;
			  b_size = t_size;
			  b_rainbow = t_rainbow;
			  b_normal = t_normal;

			  for (int tr = 0; tr < N; tr++) {
				  for (int tc = 0; tc < N; tc++) {
					  block_check[tr][tc] = tmp_check[tr][tc];
				  }
			  }
			}
		  }
		}
	  }
	}
  }

  // 점수를 얻는다.
  if(b_size >= 2 && b_normal >= 1){
    int start_r = b_r;
	int start_c = b_c;
	int s_color = map[b_r][b_c];

	for(int tr=0; tr<N; tr++){
	  for(int tc=0; tc<N; tc++){
	    if(block_check[tr][tc])
		  map[tr][tc] = -2;
	  }
	}

	ans += b_size*b_size;
    return true;
  }

  return false;
}

void copy_map(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  map[i][j] = tmp_map[i][j];
	}
  }
}

void do_gravity(){
  memset(tmp_map, 0, sizeof(tmp_map));

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  tmp_map[i][j] = -2;
	}
  }

  for(int i=N-1; i>=0; i--){
    for(int j=0; j<N; j++){
	  int cur_r = i;
	  int cur_c = j;

	  if(map[cur_r][cur_c] == -1){
	    tmp_map[cur_r][cur_c] = -1;
		continue;
	  }
	  
	  while(true){
	    if(cur_r == N-1)
		  break;
		if(tmp_map[cur_r+1][cur_c] != -2)
		  break;
		cur_r++;
	  }

	  tmp_map[cur_r][cur_c] = map[i][j];
	}
  }

  copy_map();
  return;
}

void turn_counter_clockwise(){
  memset(tmp_map, 0, sizeof(tmp_map));

  for(int i=0; i<N; i++){
    for(int j=N-1; j>=0; j--){
	  tmp_map[j][i] = map[i][N-1-j];
	}
  }

  copy_map();
  return;
}

void solve(){
  while(true){
    // 블록 그룹을 찾아 제거 (최소 크기 2)
    if(find_maxblock() == false)
	  break;

	// 격자에 중력을 작용시킴.
	do_gravity();
	
	// 격자 90도로 반시계 방향으로 회전
	turn_counter_clockwise();
	
	// 다시 격자에 중력을 작용시킴.
	do_gravity();
  }

  printf("%d\n", ans);
  return;
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  solve();
  return 0;
}
