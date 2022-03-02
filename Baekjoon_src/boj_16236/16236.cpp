#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int map[25][25] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int check[25][25] = {0};

int main(){
  int N;
  scanf("%d", &N);

  int c_r = 0;
  int c_c = 0;
  int cur_size = 2;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  int ans_time = 0;
  int eat_fish = 0;
  int stage = 1;
  queue<pair<pair<int,int>, int>> q;

  while(true){
    for(int i=0; i<N; i++){
	  for(int j=0; j<N; j++){
	    if(map[i][j] == 9){
		  c_r = i;
		  c_c = j;
		}
	  }
	}

	memset(check, 0, sizeof(check));
	q.push(make_pair(make_pair(c_r, c_c), 0));

	int min_r = -1;
	int min_c = -1;
	int min_time = 999999999;

	while (!q.empty()) {
		int cur_r = q.front().first.first;
		int cur_c = q.front().first.second;
		int cur_dis = q.front().second;
		q.pop();

		if(check[cur_r][cur_c])
		  continue;
		else
		  check[cur_r][cur_c] = 1;

		for (int i = 0; i < 4; i++) {
			int tmp_r = cur_r + dx[i];
			int tmp_c = cur_c + dy[i];

			if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= N)
			  continue;
			else {
			  if(check[tmp_r][tmp_c])
			    continue;
			  
			  int tmp_size = map[tmp_r][tmp_c];

			  if(tmp_size == 0)
				q.push(make_pair(make_pair(tmp_r, tmp_c), cur_dis + 1));

			  if(tmp_size != 0 && tmp_size <= cur_size){
			    q.push(make_pair(make_pair(tmp_r, tmp_c), cur_dis+1));

				if(tmp_size < cur_size){
				  if(min_time > cur_dis+1){
				    min_r = tmp_r;
					min_c = tmp_c;
					min_time = cur_dis+1;
				  }
				  else if(min_time == cur_dis+1){
				    if(min_r > tmp_r){
					  min_r = tmp_r;
					  min_c = tmp_c;
					}
					else if(min_r == tmp_r){
					  if(min_c > tmp_c){
					    min_r = tmp_r;
						min_c = tmp_c;
					  }
					}
				  }
				}
			  }
			}
		}
	}

	if(min_r == -1 && min_c == -1)
	  break;

	eat_fish++;

	if(eat_fish == cur_size){
	  cur_size += 1;
	  eat_fish = 0;
	}

	ans_time += min_time;
	map[min_r][min_c] = 9;
	map[c_r][c_c] = 0;
  }

  printf("%d\n", ans_time);

  return 0;
}
