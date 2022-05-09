#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct fireball {
  int r;
  int c;
  int weight;
  int velocity;
  int dir;
  bool live;
} fireball;

int N, M, K;
vector<fireball> map[55][55];
vector<fireball> tmp_map[55][55];
vector<fireball> split_map[55][55];

void calculate_weight(){
  int all_weight = 0;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  for(int k=0; k<map[i][j].size(); k++){
	    if(map[i][j].at(k).live == true)
		  all_weight += map[i][j].at(k).weight;
	  }
	}
  }

  printf("%d\n", all_weight);
  return;
}

void init_tmp_map(){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  tmp_map[i][j].clear();
	  split_map[i][j].clear();
	}
  }

  return;
}

void move_fireballs(){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  for(int k=0; k<map[i][j].size(); k++){
	    if(map[i][j].at(k).live == true){
		  int cur_r = map[i][j].at(k).r;
		  int cur_c = map[i][j].at(k).c;
		  int cur_weight = map[i][j].at(k).weight;
		  int cur_velocity = map[i][j].at(k).velocity;
		  int cur_dir = map[i][j].at(k).dir;

		  if(cur_dir == 0){ // up (r--)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r--;

			  if(cur_r < 1)
			    cur_r = N;
			}
		  }
		  else if(cur_dir == 1) { // up-right (r--, c++)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r--;
			  cur_c++;

			  if(cur_r < 1)
			    cur_r = N;
			  if(cur_c > N)
			    cur_c = 1;
			}
		  }
		  else if(cur_dir == 2) { // right (c++)
		    for(int i=0; i<cur_velocity; i++){
			  cur_c++;

		      if (cur_c > N)
			    cur_c = 1;
			}
		  }
		  else if(cur_dir == 3) { // down-right (r++, c++)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r++;
			  cur_c++;

			  if(cur_r > N)
			    cur_r = 1;
			  if(cur_c > N)
			    cur_c = 1;
			}
		  }
		  else if(cur_dir == 4) {  // down (r++)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r++;

			  if (cur_r > N)
			    cur_r = 1;
			}
		  }
		  else if(cur_dir == 5) { // left-down (r++, c--)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r++;
			  cur_c--;

			  if(cur_r > N)
			    cur_r = 1;
			  if(cur_c < 1)
			    cur_c = N;
			}
		  }
		  else if(cur_dir == 6) {  // left (c--)
		    for(int i=0; i<cur_velocity; i++){
			  cur_c--;

			  if(cur_c < 1)
			    cur_c = N;
			}
		  }
		  else if(cur_dir == 7){ // up-left (r--, c--)
		    for(int i=0; i<cur_velocity; i++){
			  cur_r--;
			  cur_c--;

			  if(cur_r < 1)
			    cur_r = N;
			  if(cur_c < 1)
			    cur_c = N;
			}
		  }

		  fireball tmp_fb2 = {cur_r, cur_c, cur_weight, cur_velocity, cur_dir, true};
		  tmp_map[cur_r][cur_c].push_back(tmp_fb2);
		}
	  }
	}
  }

  return;
}

void split_fireballs(){
  // tmp_map에서 쪼개서 split_map에 저장
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  if(tmp_map[i][j].size() == 0)
	    continue;

	  if(tmp_map[i][j].size() == 1){
	    split_map[i][j].push_back(tmp_map[i][j].at(0));
		continue;
	  }

	  int sum_weight = 0;
	  int sum_velocity = 0;
	  int n_odd_dir = 0;
	  int n_even_dir = 0;

	  for(int k=0; k<tmp_map[i][j].size(); k++){
	    sum_weight += tmp_map[i][j].at(k).weight;
		sum_velocity += tmp_map[i][j].at(k).velocity;

		if(tmp_map[i][j].at(k).dir % 2 == 0)
		  n_even_dir++;
		else if(tmp_map[i][j].at(k).dir % 2 == 1)
		  n_odd_dir++;
	  }

	  sum_weight /= 5;
	  sum_velocity /= tmp_map[i][j].size();

	  if(sum_weight == 0)
	    continue;

	  if(n_odd_dir == tmp_map[i][j].size() || n_even_dir == tmp_map[i][j].size()){
	    fireball tmp_fb_1 = { i, j, sum_weight, sum_velocity, 0, true };
		fireball tmp_fb_2 = { i, j, sum_weight, sum_velocity, 2, true };
		fireball tmp_fb_3 = { i, j, sum_weight, sum_velocity, 4, true };
		fireball tmp_fb_4 = { i, j, sum_weight, sum_velocity, 6, true };
		split_map[i][j].push_back(tmp_fb_1);
		split_map[i][j].push_back(tmp_fb_2);
		split_map[i][j].push_back(tmp_fb_3);
		split_map[i][j].push_back(tmp_fb_4);
	  }
	  else {
		fireball tmp_fb_1 = { i, j, sum_weight, sum_velocity, 1, true };
		fireball tmp_fb_2 = { i, j, sum_weight, sum_velocity, 3, true };
		fireball tmp_fb_3 = { i, j, sum_weight, sum_velocity, 5, true };
		fireball tmp_fb_4 = { i, j, sum_weight, sum_velocity, 7, true };
		split_map[i][j].push_back(tmp_fb_1);
		split_map[i][j].push_back(tmp_fb_2);
		split_map[i][j].push_back(tmp_fb_3);
		split_map[i][j].push_back(tmp_fb_4);
	  }
	}
  }

  return;
}

void copy_map(){
  // split_map을 map으로 복제
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  map[i][j].clear();

	  for(int k=0; k<split_map[i][j].size(); k++){
	    map[i][j].push_back(split_map[i][j].at(k));
	  }
	}
  }

  return;
}

void solve(){
  while(K--){
    // 0. tmp_map 초기화
	init_tmp_map();

	// 1. 파이어볼 이동
	move_fireballs();

	// 2. 이동끝난 뒤 쪼개기
	split_fireballs();

	// 3. tmp_map을 map으로 복제
	copy_map();
  }

  calculate_weight();
  return;
}

int main(){
  scanf("%d %d %d", &N, &M, &K);

  int r, c, m, s, d;
  for(int i=0; i<M; i++){
    scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
	fireball tmp_fb = {r, c, m ,s, d, true};
	map[r][c].push_back(tmp_fb);
  }

  solve();
  return 0;
}
