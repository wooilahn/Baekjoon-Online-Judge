#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int map[5][5] = {0};
vector<int> v;

bool check_bingo() {
  // 가로
  int bingo_cnt = 0;

  for(int i=0; i<5; i++){
    int h_cnt = 0;
	int v_cnt = 0;


	// 가로
	for(int k=0; k<5; k++){
	  if(map[i][k] == -1)
	    h_cnt++;
	}

	// 세로
	for(int k=0; k<5; k++){
	  if(map[k][i] == -1)
	    v_cnt++;
	}

	if(h_cnt == 5)
	  bingo_cnt++;
	if(v_cnt == 5)
	  bingo_cnt++;
  }

  int d1_cnt = 0;
  int d2_cnt = 0;

  for (int k = 0; k < 5; k++) {
	  if (map[k][k] == -1)
		  d1_cnt++;
  }

  for (int k = 0; k < 5; k++) {
	  if (map[k][4 - k] == -1)
		  d2_cnt++;
  }

  if(d1_cnt >= 5)
    bingo_cnt++;
  if(d2_cnt >= 5)
    bingo_cnt++;

  if(bingo_cnt >= 3)
    return true;

  return false;
}

int main(){
  
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  int num = 0;
  for(int i=0; i<25; i++){
    scanf("%d", &num);
	v.push_back(num);
  }

  for(int i=0; i<25; i++){
	for(int r=0; r<5; r++){
	  for(int c=0; c<5; c++){
	    if(map[r][c] == v[i])
		  map[r][c] = -1;
	  }
	}

	if(check_bingo() == true){
	  printf("%d\n", i+1);
	  break;
	}
  }

  return 0;
}
