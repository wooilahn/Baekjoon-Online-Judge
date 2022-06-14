#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

typedef struct fish {
  int r;
  int c;
  int d;
} fish;

int M, S;

int smell_map[5][5] = {0};
vector<fish> fish_map[5][5];
vector<fish> copy_map[5][5];

int s_r, s_c;
int max_eat_fish = 0;

int tmp_route[3] = {0};
int route[3] = {0};

int fx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int fy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int sx[5] = { 0, -1, 0, 1, 0 };
int sy[5] = { 0, 0, -1, 0, 1 };

int answer = 0;

void copy_fish(){
  for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
	  copy_map[i][j] = fish_map[i][j];
	}
  }
  return;
}

void copy_maps(vector<fish> A[][5], vector<fish> B[][5]){
  for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
	  A[i][j] = B[i][j];
	}
  }
  return;
}

int changeDir(int dir){
  switch(dir){
    case 1:
	  return 8;
	case 2:
	  return 1;
	case 3:
	  return 2;
	case 4:
	  return 3;
	case 5:
	  return 4;
	case 6:
	  return 5;
	case 7:
	  return 6;
	case 8:
	  return 7;
  }
}

void move_fish(){
  vector<fish> tmp_map[5][5];

  for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
	  for(int k=0; k<fish_map[i][j].size(); k++){
	    int cur_r = fish_map[i][j][k].r;
		int cur_c = fish_map[i][j][k].c;
		int cur_dir = fish_map[i][j][k].d;

		int tmp_r = cur_r;
		int tmp_c = cur_c;
		bool find_flag = false;

		for(int t=0; t<8; t++){
		  tmp_r = cur_r + fx[cur_dir];
		  tmp_c = cur_c + fy[cur_dir];

		  if(tmp_r >= 1 && tmp_r <= 4 && tmp_c >= 1 && tmp_c <= 4){
		    if((tmp_r != s_r || tmp_c != s_c) && smell_map[tmp_r][tmp_c] == 0){
			  find_flag = true;
			  break;
			}
		  }

		  cur_dir = changeDir(cur_dir);
		}

		if(find_flag)
		  tmp_map[tmp_r][tmp_c].push_back( {tmp_r, tmp_c, cur_dir} );
		else if(!find_flag)
		  tmp_map[cur_r][cur_c].push_back( {cur_r, cur_c, cur_dir} );
	  }
	}
  }

  copy_maps(fish_map, tmp_map);
  return;
}

void find_route(int cnt) {
  if(cnt == 3){
    bool visited[5][5] = {0};
    int cur_eat_fish = 0;
    int tmp_r = s_r;
	int tmp_c = s_c;

	for(int i=0; i<3; i++){
		if (tmp_route[i] == 1) // 상(r--)
			tmp_r--;
		else if (tmp_route[i] == 2)  // 좌(c--)
			tmp_c--;
		else if (tmp_route[i] == 3)  // 하(r++)
			tmp_r++;
		else if (tmp_route[i] == 4)  // 우(c++)
			tmp_c++;

		if(visited[tmp_r][tmp_c] == false){
		  visited[tmp_r][tmp_c] = true;
		  cur_eat_fish += fish_map[tmp_r][tmp_c].size();
		}
	}

	if(cur_eat_fish > max_eat_fish){
	  for(int i=0; i<3; i++)
	    route[i] = tmp_route[i];
	  max_eat_fish = cur_eat_fish;
	}
	return;
  }

  for(int i=1; i<=4; i++){
    tmp_route[cnt] = i;
	int temp_r = s_r;
	int temp_c = s_c;

	for(int t=0; t<=cnt; t++){
	  if (tmp_route[t] == 1) // 상(r--)
		  temp_r--;
	  else if (tmp_route[t] == 2)  // 좌(c--)
		  temp_c--;
	  else if (tmp_route[t] == 3)  // 하(r++)
		  temp_r++;
	  else if (tmp_route[t] == 4)  // 우(c++)
		  temp_c++;
	}

	if(temp_r <= 0 || temp_r > 4 || temp_c <= 0 || temp_c > 4)
	  continue;

	find_route(cnt+1);
  }

  return;
}

void make_smell(int time){
  for(int i=0; i<3; i++){
    if(route[i] == 1) // 상(r--)
	  s_r--;
	else if(route[i] == 2)  // 좌(c--)
	  s_c--;
	else if(route[i] == 3)  // 하(r++)
	  s_r++;
	else if(route[i] == 4)  // 우(c++)
	  s_c++;

	if(fish_map[s_r][s_c].size() > 0){
	  smell_map[s_r][s_c] = time;
	  fish_map[s_r][s_c].clear();
	}
  }

  return;
}

void move_shark(int time){
  max_eat_fish = -1;
  find_route(0);
  make_smell(time);

  return;
}

void remove_smell(int time){
  for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
	  if(smell_map[i][j] == 0)
	    continue;
	  if(time - smell_map[i][j] >= 2)
	    smell_map[i][j] = 0;
	}
  }

  return;
}

void born_fish() {
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=4; j++) {
			for (int k = 0; k<copy_map[i][j].size(); k++) {
				fish_map[i][j].push_back(copy_map[i][j][k]);
			}
		}
	}

	return;
}

void find_answer(){
  answer = 0;
  for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
	  answer += fish_map[i][j].size();
	}
  }
}

void solve(){
  for(int i=1; i<=S; i++){
    // 1. 복제마법을 시전한다.
    copy_fish();

	// 2. 모든 물고기가 1칸 이동한다.
	move_fish();

	// 3. 상어가 연속해서 3칸을 이동한다.
	move_shark(i);

	// 4. 두번 전 연습에서 물고기 냄새가 사라진다.
	remove_smell(i);

	// 5. 복제마법이 완료된다.
	born_fish();

  }
  
  find_answer();
  printf("%d\n", answer);
  return;
}

int main(){
  scanf("%d %d", &M, &S);
  for(int i=0; i<M; i++){
    int x, y, d;
	scanf("%d %d %d", &x, &y, &d);
	fish_map[x][y].push_back({x, y, d});
  }
  scanf("%d %d", &s_r, &s_c);
  solve();
  return 0;
}
