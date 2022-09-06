#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char map[105][105] = {0};
bool chk[105][105] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;

void dfs(int r, int c, char tar){

  queue<pair<int,int>> q;
  q.push(make_pair(r,c));

  while(!q.empty()){
    int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();

	if(chk[cur_r][cur_c])
	  continue;
	else
	  chk[cur_r][cur_c] = true;

	for(int i=0; i<4; i++){
	  int tmp_r = cur_r + dx[i];
	  int tmp_c = cur_c + dy[i];

	  if(tmp_r<0 || tmp_c<0 || tmp_r>=N || tmp_c>=N)
	    continue;
	  if(map[tmp_r][tmp_c] == tar)
	    q.push(make_pair(tmp_r, tmp_c));
	}
  }

  return;  
}

void change_map(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  if(map[i][j] == 'G')
	    map[i][j] ='R';
	}
  }

  return;
}


int main(){
  scanf("%d", &N);

  for(int i=0; i<N; i++)
    scanf("%s", map[i]);

  int not_blind_cnt = 0;
  int blind_cnt = 0;

  for(int r=0; r<N; r++){
    for(int c=0; c<N; c++){
	  if(chk[r][c])
	    continue;

	  dfs(r, c, map[r][c]);
	  not_blind_cnt++;
	}
  }

  memset(chk, 0, sizeof(chk));
  change_map();

  for(int r=0; r<N; r++){
    for(int c=0; c<N; c++){
	  if(chk[r][c])
	    continue;
	  
	  dfs(r, c, map[r][c]);
	  blind_cnt++;
	}
  }

  printf("%d %d\n", not_blind_cnt, blind_cnt);
 
  return 0;
}
