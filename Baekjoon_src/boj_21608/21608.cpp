#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int ans = 0;
int tar_stu, p_stu1, p_stu2, p_stu3, p_stu4;

int map[25][25] = {0};
int stu_pos[402][2] = {0}; // [i][0]: row, [i][1]: col
vector<int> students[402];
// 0: student_num, 1~4: 선호번호 학생 수

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void find_position(){
  int cur_r = 999;
  int cur_c = 999;
  int cur_prefer = 0;
  int cur_space = 0;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
	  int tmp_prefer = 0;
	  int tmp_space = 0;

	  if(map[i][j] > 0)
	    continue;

	  for(int k=0; k<4; k++){
	    int tmp_r = i + dx[k];
		int tmp_c = j + dy[k];

		if(tmp_r <= 0 || tmp_r > N || tmp_c <= 0 || tmp_c > N)
		  continue;

		if(map[tmp_r][tmp_c] == p_stu1 || map[tmp_r][tmp_c] == p_stu2 || map[tmp_r][tmp_c] == p_stu3 || map[tmp_r][tmp_c] == p_stu4)
		  tmp_prefer++;
		if(map[tmp_r][tmp_c] == 0)
		  tmp_space++;
	  }

	  // 선호하는 학생 수가 더 많을 때
	  if(tmp_prefer > cur_prefer){
	    cur_prefer = tmp_prefer;
		cur_space = tmp_space;
		cur_r = i;
		cur_c = j;
	  }
	  else if(tmp_prefer == cur_prefer){
	    // 주변 빈칸이 더 많을 때
	    if(tmp_space > cur_space){
		  cur_space = tmp_space;
		  cur_r = i;
		  cur_c = j;
		}
		else if(tmp_space == cur_space){
		  // 행의 수가 더 작을 때
		  if(cur_r > i){
		    cur_r = i;
			cur_c = j;
		  }
		  else if(cur_r == i){
		    if(cur_c > j){
			  cur_r = i;
			  cur_c = j;
			}
		  }
		}
	  }
	}
  }

  map[cur_r][cur_c] = tar_stu;
  stu_pos[tar_stu][0] = cur_r;
  stu_pos[tar_stu][1] = cur_c;
  return;
}

void calculate_preference(){
  // 각 학생의 선호도 조사
  for(int i=0; i<N*N; i++){
    int cur_stu = students[i].at(0);

	p_stu1 = students[i].at(1);
	p_stu2 = students[i].at(2);
	p_stu3 = students[i].at(3);
	p_stu4 = students[i].at(4);

	int cur_r = stu_pos[cur_stu][0];
	int cur_c = stu_pos[cur_stu][1];

	int n_prefer = 0;

	for(int k=0; k<4; k++){
	  int tmp_r = cur_r + dx[k];
	  int tmp_c = cur_c + dy[k];

	  if(tmp_r <= 0 || tmp_r > N || tmp_c <= 0 || tmp_c > N)
	    continue;

	  if(map[tmp_r][tmp_c] == p_stu1)
	    n_prefer++;
	  else if(map[tmp_r][tmp_c] == p_stu2)
	    n_prefer++;
	  else if(map[tmp_r][tmp_c] == p_stu3)
	    n_prefer++;
	  else if(map[tmp_r][tmp_c] == p_stu4)
	    n_prefer++;
	}

	if(n_prefer == 1)
	  ans += 1;
	else if(n_prefer == 2)
	  ans += 10;
	else if(n_prefer == 3)
	  ans += 100;
	else if(n_prefer == 4)
	  ans += 1000;
  }

  return;
}

void solve(){
  for(int i=0; i<N*N; i++){
    tar_stu = students[i].at(0);

	p_stu1 = students[i].at(1);
	p_stu2 = students[i].at(2);
	p_stu3 = students[i].at(3);
	p_stu4 = students[i].at(4);

	find_position();
  }

  calculate_preference();
  return;
}

int main(){
  scanf("%d", &N);

  int stu, a, b, c, d;
  for(int i=0; i<N*N; i++){
    scanf("%d %d %d %d %d", &stu, &a, &b, &c, &d);
	students[i].push_back(stu);
	students[i].push_back(a);
	students[i].push_back(b);
	students[i].push_back(c);
	students[i].push_back(d);
  }

  solve();
  printf("%d\n", ans);

  return 0;
}
