#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
int answer = 99999;
int line[33][13][13] = {0};

bool check_ladder(){
  for(int i=1; i<=N; i++){
    int cur_pos = i;

	for(int k=1; k<=H; k++){
	  if(line[k][cur_pos][cur_pos-1] > 0)
	    cur_pos = cur_pos-1;
	  else if(line[k][cur_pos][cur_pos+1] > 0)
	    cur_pos = cur_pos+1;
	}

	if(cur_pos != i)
	  return false;
  }
  return true;
}

void solve(int cur_h, int cur_n, int idx, int tar){
  if(idx <= tar){
    if(check_ladder()){
	  answer = min(answer, idx);
	  return;
	}
	if(idx == tar)
	  return;
  }

  // 사다리 고르는 선택
  for(int j=cur_n; j<=N-1; j++){
	if (line[cur_h][j][j-1] > 0 || line[cur_h][j][j+1] > 0)
		  continue;

    line[cur_h][j][j+1] = 1;
	line[cur_h][j+1][j] = 1;
	solve(cur_h, j, idx+1, tar);
	line[cur_h][j][j+1] = 0;
	line[cur_h][j+1][j] = 0;
  }

  for(int i=cur_h+1; i<=H; i++){ 
    for(int j=1; j<=N-1; j++){ 
	  if(line[i][j][j-1] > 0 || line[i][j][j+1] > 0)
	    continue;
	  else {
		line[i][j][j+1] = 1;
		line[i][j+1][j] = 1;
		solve(i, j, idx+1, tar);
		line[i][j][j+1] = 0;
		line[i][j+1][j] = 0;
	  }
	}
  }

  return;
}

int main(){
  scanf("%d %d %d", &N, &M, &H);
  int a, b;

  for(int i=0; i<M; i++){
    scanf("%d %d", &a, &b);
	line[a][b][b+1] = 2;
	line[a][b+1][b] = 2;
  }

  solve(1, 1, 0, 3);
 
  if(answer > 3)
    printf("-1\n");
  else
    printf("%d\n", answer);

  return 0;
}
