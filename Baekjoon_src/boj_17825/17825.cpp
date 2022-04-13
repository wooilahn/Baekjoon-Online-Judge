#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int kgt[5][2] = {0}; // [0]: location [1]: yut kind (0: outside, 1: 10~19, 2: 20~24, 3: 30~26, 4:25~40)
int dice[15] = {0};
int ans = 0;
int cur_type;

int move_operation(int pos, int k_type, int move_value){
  int res_pos = pos;

  if(k_type == 0){ // 0: outside
    res_pos = res_pos + 2*move_value;
	cur_type = 0;

	if(res_pos == 10)
      cur_type = 1;
	else if(res_pos == 20)
	  cur_type = 2;
	else if(res_pos == 30)
	  cur_type = 3;
	else if(res_pos >= 40)
	  cur_type = 4;
  }
  else if(k_type == 1){ // 1: 10~19
	cur_type = 1;
    for(int k=0; k<move_value; k++){
	  if(res_pos < 19)
	    res_pos += 3;
	  else if(res_pos == 19){
	    res_pos = 25;
		cur_type = 4;
	  }
	  else if(res_pos >= 25)
	    res_pos += 5;
	}
  }
  else if(k_type == 2){ // 2: 20~24
	cur_type = 2;
    for(int k=0; k<move_value; k++){
	  if(res_pos < 24)
	    res_pos += 2;
	  else if(res_pos == 24){
	    res_pos = 25;
		cur_type = 4;
	  }
	  else if(res_pos >= 25)
	    res_pos += 5;
	}
  }
  else if(k_type == 3){ // 3: blue 30~26
	cur_type = 3;
    for(int k=0; k<move_value; k++){
	  if(res_pos == 30 && cur_type == 3){
	    res_pos = 28;
		continue;
	  }
	  if((res_pos == 27 || res_pos == 28) && cur_type == 3){
	    res_pos -= 1;
		continue;
	  }
	  if(res_pos == 26 && cur_type == 3) {
		  res_pos = 25;
		  cur_type = 4;
		  continue;
	  }
	  
	  res_pos += 5;
	}
  }
  else if(k_type == 4){ // 4: 25~40
	cur_type = 4;
    res_pos = res_pos + 5*move_value;
  }

  return res_pos;
}

void solve(int dice_idx, int move_kgt, int cur_score){
  if(dice_idx == 10){
    ans = max(ans, cur_score);
	return;
  }

  if(kgt[move_kgt][0] > 40)
    return;

  int cur_dice = dice[dice_idx];
  int move_pos = move_operation(kgt[move_kgt][0], kgt[move_kgt][1], cur_dice);

  for(int i=1; i<=4; i++){
    if(move_pos <= 40 && kgt[i][0]==move_pos && kgt[i][1]==cur_type)
	  return;
  }

  kgt[move_kgt][0] = move_pos;
  kgt[move_kgt][1] = cur_type;

  if(move_pos > 40)
    move_pos = 0;

  int ori_pos, ori_type;

  // Move Knight 1
  ori_pos  = kgt[1][0];
  ori_type = kgt[1][1];
  solve(dice_idx + 1, 1, cur_score + move_pos);
  kgt[1][0] = ori_pos;
  kgt[1][1] = ori_type;

  // Move Knight 2
  ori_pos  = kgt[2][0];
  ori_type = kgt[2][1];
  solve(dice_idx + 1, 2, cur_score + move_pos);
  kgt[2][0] = ori_pos;
  kgt[2][1] = ori_type;

  // Move Knight 3
  ori_pos  = kgt[3][0];
  ori_type = kgt[3][1];
  solve(dice_idx + 1, 3, cur_score + move_pos);
  kgt[3][0] = ori_pos;
  kgt[3][1] = ori_type;

  // Move Knight 4
  ori_pos  = kgt[4][0];
  ori_type = kgt[4][1];
  solve(dice_idx + 1, 4, cur_score + move_pos);
  kgt[4][0] = ori_pos;
  kgt[4][1] = ori_type;

  return;
}

int main(){
  for(int i=0; i<10; i++)
    scanf("%d", &dice[i]);

  // Knight 1
  memset(kgt, 0, sizeof(kgt));
  cur_type = 0;
  solve(0, 1, 0);

  // Knight 2
  memset(kgt, 0, sizeof(kgt));
  cur_type = 0;
  solve(0, 2, 0);

  // Knight 3
  memset(kgt, 0, sizeof(kgt));
  cur_type = 0;
  solve(0, 3, 0);

  // Knight 4
  memset(kgt, 0, sizeof(kgt));
  cur_type = 0;
  solve(0, 4, 0);

  printf("%d\n", ans);
  return 0;
}
