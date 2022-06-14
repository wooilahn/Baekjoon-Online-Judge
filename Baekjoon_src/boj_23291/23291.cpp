#define _CRT_SECURE_NO_WARNINGS
#define MAX 110

#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int N, K;
int ans = 0;
deque<int> board[MAX];

int dx[2] = { 0, -1 };
int dy[2] = { 1, 0  };

bool check_fish(){
  int min_fish = 999999999;
  int max_fish = -999999999;

  for(int i=0; i<board[0].size(); i++){
    min_fish = min(min_fish, board[0][i]);
	max_fish = max(max_fish, board[0][i]);
  }

  return (max_fish-min_fish <= K) ? true : false;
}

void add_fish(){
  int min_fish = 999999999;

  for(int i=0; i<board[0].size(); i++){
    if(min_fish > board[0][i])
	  min_fish = board[0][i];
  }

  for(int i=0; i<board[0].size(); i++){
    if(board[0][i] == min_fish)
	  board[0][i] += 1;
  }

  return;
}

bool check_board(int w, int h){
  if(board[0].size()-w < h)
    return false;
  else
    return true;
}

int modify_board(){
  int width = 1;
  int height = 1;
  bool change_flag = false;

  while(true){
    if(check_board(width, height) == false)
	  break;

	int t_width = width;

	for(int i=0; i<width; i++, t_width--){
	  int idx = 0;
	  for(int j=0; j<height; j++, idx++){
	    board[t_width].push_back(board[idx][i]);
	  }
	}

	for(int i=0; i<height; i++){
	  for(int j=0; j<width; j++){
	    board[i].pop_front();
	  }
	}

	if(change_flag == false){
	  height++;
	  change_flag = true;
	}
	else if(change_flag == true){
	  width++;
	  change_flag = false;
	}
  }

  return height;
}

void adjust_fish(int h){
  deque<int> tmp_board[MAX];

  for(int i=0; i<h; i++)
    tmp_board[i] = board[i];
  
  for(int i=h-1; i>=0; i--){
    for(int j=0; j<board[i].size(); j++){
	  int cur_r = i;
	  int cur_c = j;
	  int num1 = board[cur_r][cur_c];

	  for(int k=0; k<2; k++){
	    int tmp_r = cur_r + dx[k];
		int tmp_c = cur_c + dy[k];

		if(tmp_r >= 0 && tmp_c < board[i].size()){
		  int num2 = board[tmp_r][tmp_c];

		  int fish_dis = abs(num1 - num2) / 5;

		  if(num1 > num2){
		    tmp_board[cur_r][cur_c] -= fish_dis;
			tmp_board[tmp_r][tmp_c] += fish_dis;
		  }
		  else if(num1 < num2){
		    tmp_board[cur_r][cur_c] += fish_dis;
			tmp_board[tmp_r][tmp_c] -= fish_dis;
		  }
		}
	  }
	}
  }
  
  for(int i=0; i<h; i++)
    board[i] = tmp_board[i];

  return;
}

void flatten_board(int h){
  int w = board[h-1].size();
  int base_size = board[0].size();

  for(int i=0; i<w; i++){
    for(int j=0; j<h; j++){
	  board[0].push_back(board[j][i]);
	}
  }

  for(int i=1; i<h; i++)
    board[i].clear();

  for(int i=w; i<base_size; i++)
    board[0].push_back(board[0][i]);

  for(int i=0; i<base_size; i++)
    board[0].pop_front();

  return; 
}

void modify_board2() {
  int n = board[0].size();

  for(int i=0; i<n/2; i++)
    board[1].push_front(board[0][i]);

  for(int i=0; i<n/2; i++)
    board[0].pop_front();

  for(int i=0; i<n/4; i++){
    board[2].push_front(board[1][i]);
	board[3].push_front(board[0][i]);
  }

  for(int i=0; i<n/4; i++){
    board[0].pop_front();
	board[1].pop_front();
  }

  return;
}

void solve(){
  while(true){
    if(check_fish()){
	  printf("%d\n", ans);
	  break;
	}

	// 1. 물고기를 추가한다.
	add_fish();

	// 2. 어항을 공중부양 시킨다.
	int h = modify_board();

	// 3. 어항속의 물고기 수를 조절한다.
	adjust_fish(h);

	// 4. 어항을 바닥에 일렬로 놓는다.
	flatten_board(h);

	// 5. 어항을 다른 방법으로 공중부양 시킨다.
	modify_board2();

	// 6. 나머지 작업을 수행한다.
	adjust_fish(4);
	flatten_board(4);
    ans++;
  }

  return;
}

int main(){
  scanf("%d %d", &N, &K);
  int num;
  for(int i=0; i<N; i++){
    scanf("%d", &num);
	board[0].push_back(num);
  }

  solve();

  return 0;
}
