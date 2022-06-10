#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int ans = 0;
int map[55][55] = {0};
int tmp_map[55][55] = {0};

bool cloud_check[55][55] = {0};

vector<int> d_v;
vector<int> s_v;
vector<pair<int,int>> cloud;

int dx[9] = {777, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {777, -1, -1, 0, 1, 1, 1, 0, -1};

int dia_x[4] = {-1, -1, 1, 1};
int dia_y[4] = {-1, 1, -1, 1};

void add_rain(){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	    map[i][j] += tmp_map[i][j];
	}
  }

  return;
}

void move_cloud(int d, int s){
  int move_r = dx[d];
  int move_c = dy[d];


  for(int k=0; k<cloud.size(); k++){
    int cur_r = cloud[k].first;
	int cur_c = cloud[k].second;

	for (int i=0; i<s; i++) {
		cur_r += move_r;
		cur_c += move_c;

		if (cur_r == 0)
			cur_r = N;
		if (cur_r == N+1)
			cur_r = 1;

		if (cur_c == 0)
			cur_c = N;
		if (cur_c == N+1)
			cur_c = 1;
	}

	cloud[k].first = cur_r;
	cloud[k].second = cur_c;
  }

  return;
}

void drop_rain(){
  for(int i=0; i<cloud.size(); i++)
    map[cloud[i].first][cloud[i].second]++;
  
  return;
}

void copy_rain() {
  memset(tmp_map, 0, sizeof(tmp_map));

  for(int i=0; i<cloud.size(); i++){
    int cur_r = cloud[i].first;
	int cur_c = cloud[i].second;

	int n_diagonal = 0;

	for(int k=0; k<4; k++){
	  int tmp_r = cur_r + dia_x[k];
	  int tmp_c = cur_c + dia_y[k];

	  if(tmp_r <= 0 || tmp_r > N || tmp_c <= 0 || tmp_c > N)
	    continue;
	  if(map[tmp_r][tmp_c] > 0)
	    n_diagonal++;
	}

	tmp_map[cur_r][cur_c] = n_diagonal;
  }

  add_rain();
  return;
}

void disappear_cloud(){
	// 사라지는 구름 칸 체크
	for (int k=0; k<cloud.size(); k++) {
		int c_r = cloud[k].first;
		int c_c = cloud[k].second;
		cloud_check[c_r][c_c] = true;
	}
}

void calculate_basket(){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  ans += map[i][j];
	}
  }

  printf("%d\n", ans);
  return;
}

void solve(){
  for(int i=0; i<M; i++){
    cloud.clear();

	// 구름 추가
	if(i == 0){
	  cloud.push_back(make_pair(N, 1));
	  cloud.push_back(make_pair(N, 2));
	  cloud.push_back(make_pair(N-1, 1));
	  cloud.push_back(make_pair(N-1, 2));
	}
	else {
	  for(int r=1; r<=N; r++){
	    for(int c=1; c<=N; c++){
		  if(map[r][c] >= 2 && cloud_check[r][c] == false){
		    cloud.push_back(make_pair(r,c));
			map[r][c] -= 2;
		  }
		}
	  }
	}

	memset(cloud_check, 0, sizeof(cloud_check));

	// 모든 구름이 d_i 방향으로 s_i 칸 이동
	move_cloud(d_v[i], s_v[i]);

	// 각 구름에서 비가 내려 칸의 바구니에 저장되 물의 양이 1증가
	drop_rain();

	// 물복사 버그 마법 시전
	copy_rain();

	// 사라지는 구름 칸 체크
	disappear_cloud();

	if(i == M-1){
		cloud.clear();
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (map[r][c] >= 2 && cloud_check[r][c] == false) {
					cloud.push_back(make_pair(r, c));
					map[r][c] -= 2;
				}
			}
		}
	}
  }

  // 정답 계산
  calculate_basket();

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
