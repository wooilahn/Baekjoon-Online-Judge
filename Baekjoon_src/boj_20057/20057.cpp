#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N;
int map[503][503] = {0};

int ans = 0;
int tornado_r, tornado_c;

int cur_dir = 0; // 0:서(c--), 1:남(r++), 2:동(c++), 3:북(r--)
int cur_move = 0;
int move_cnt = 1;
int turn_cnt = 0;

void move_tornado(){
  if(turn_cnt == 2){
    turn_cnt = 0;
    move_cnt++;
  }

  if(cur_move == move_cnt){
    cur_move = 0;
    turn_cnt++;
    cur_dir++;
    cur_dir %= 4;
  }
  
  cur_move++;

  if(cur_dir == 0) // 서(c--)
    tornado_c--; 
  else if(cur_dir == 1) // 남(r++)
    tornado_r++; 
  else if(cur_dir == 2) // 동(c++)
    tornado_c++;
  else if(cur_dir == 3) // 북(r--)
    tornado_r--;
  
  return;
}

void move_sand(){
  int tar_sand = map[tornado_r][tornado_c];
  int remain_sand = map[tornado_r][tornado_c];
  map[tornado_r][tornado_c] = 0;

  if(cur_dir == 0){ // 서 
    // 1%
    int one_r1 = tornado_r - 1;
    int one_c1 = tornado_c + 1;
    int one_r2 = tornado_r + 1;
    int one_c2 = tornado_c + 1;

    remain_sand -= tar_sand / 100;
    remain_sand -= tar_sand / 100;

    if(one_r1 >= N || one_r1 < 0 || one_c1 >= N || one_c1 < 0)
      ans += tar_sand / 100;
    else 
      map[one_r1][one_c1] += tar_sand / 100;

    if(one_r2 >= N || one_r2 < 0 || one_c2 >= N || one_c2 < 0)
      ans += tar_sand / 100;
    else
      map[one_r2][one_c2] += tar_sand / 100;

    // 2%
    int two_r1 = tornado_r - 2;
    int two_c1 = tornado_c;
    int two_r2 = tornado_r + 2;
    int two_c2 = tornado_c;

    remain_sand -= tar_sand*2 / 100;
    remain_sand -= tar_sand*2 / 100;

    if(two_r1 >= N || two_r1 < 0 || two_c1 >= N || two_c1 < 0)
      ans += tar_sand*2 / 100;
    else 
      map[two_r1][two_c1] += tar_sand*2 / 100;

    if(two_r2 >= N || two_r2 < 0 || two_c2 >= N || two_c2 < 0)
      ans += tar_sand*2 / 100;
    else
      map[two_r2][two_c2] += tar_sand*2 / 100;
 
    // 5%
    int five_r = tornado_r;
    int five_c = tornado_c - 2;

    remain_sand -= tar_sand*5 / 100;
    
    if(five_r >= N || five_r < 0 || five_c >= N || five_c < 0)
      ans += tar_sand*5 / 100;
    else
      map[five_r][five_c] += tar_sand*5 / 100;

    // 7%
    int seven_r1 = tornado_r - 1;
    int seven_c1 = tornado_c;
    int seven_r2 = tornado_r + 1;
    int seven_c2 = tornado_c;

    remain_sand -= tar_sand*7 / 100;
    remain_sand -= tar_sand*7 / 100;

    if(seven_r1 >= N || seven_r1 < 0 || seven_c1 >= N || seven_c1 < 0)
      ans += tar_sand*7 / 100;
    else 
      map[seven_r1][seven_c1] += tar_sand*7 / 100;

    if(seven_r2 >= N || seven_r2 < 0 || seven_c2 >= N || seven_c2 < 0)
      ans += tar_sand*7 / 100;
    else
      map[seven_r2][seven_c2] += tar_sand*7 / 100;

    // 10%
    int ten_r1 = tornado_r + 1;
    int ten_c1 = tornado_c - 1;
    int ten_r2 = tornado_r - 1;
    int ten_c2 = tornado_c - 1;

    remain_sand -= tar_sand*10 / 100;
    remain_sand -= tar_sand*10 / 100;

    if(ten_r1 >= N || ten_r1 < 0 || ten_c1 >= N || ten_c1 < 0)
      ans += tar_sand*10 / 100;
    else 
      map[ten_r1][ten_c1] += tar_sand*10 / 100;

    if(ten_r2 >= N || ten_r2 < 0 || ten_c2 >= N || ten_c2 < 0)
      ans += tar_sand*10 / 100;
    else
      map[ten_r2][ten_c2] += tar_sand*10 / 100;

    // alpha
    int alpha_r = tornado_r;
    int alpha_c = tornado_c - 1;

    if(alpha_r >= N || alpha_r < 0 || alpha_c >= N || alpha_c < 0)
      ans += remain_sand;
    else
      map[alpha_r][alpha_c] += remain_sand;
  }
  else if(cur_dir == 1){ // 남
    // 1%
    int one_r1 = tornado_r - 1;
    int one_c1 = tornado_c + 1;
    int one_r2 = tornado_r - 1;
    int one_c2 = tornado_c - 1;

    remain_sand -= tar_sand / 100;
    remain_sand -= tar_sand / 100;

    if(one_r1 >= N || one_r1 < 0 || one_c1 >= N || one_c1 < 0)
      ans += tar_sand / 100;
    else 
      map[one_r1][one_c1] += tar_sand / 100;

    if(one_r2 >= N || one_r2 < 0 || one_c2 >= N || one_c2 < 0)
      ans += tar_sand / 100;
    else
      map[one_r2][one_c2] += tar_sand / 100;

    // 2%
    int two_r1 = tornado_r;
    int two_c1 = tornado_c - 2;
    int two_r2 = tornado_r;
    int two_c2 = tornado_c + 2;

    remain_sand -= tar_sand*2 / 100;
    remain_sand -= tar_sand*2 / 100;

    if(two_r1 >= N || two_r1 < 0 || two_c1 >= N || two_c1 < 0)
      ans += tar_sand*2 / 100;
    else 
      map[two_r1][two_c1] += tar_sand*2 / 100;

    if(two_r2 >= N || two_r2 < 0 || two_c2 >= N || two_c2 < 0)
      ans += tar_sand*2 / 100;
    else
      map[two_r2][two_c2] += tar_sand*2 / 100;
 
    // 5%
    int five_r = tornado_r + 2;
    int five_c = tornado_c;

    remain_sand -= tar_sand*5 / 100;
    
    if(five_r >= N || five_r < 0 || five_c >= N || five_c < 0)
      ans += tar_sand*5 / 100;
    else
      map[five_r][five_c] += tar_sand*5 / 100;

    // 7%
    int seven_r1 = tornado_r;
    int seven_c1 = tornado_c - 1;
    int seven_r2 = tornado_r;
    int seven_c2 = tornado_c + 1;

    remain_sand -= tar_sand*7 / 100;
    remain_sand -= tar_sand*7 / 100;

    if(seven_r1 >= N || seven_r1 < 0 || seven_c1 >= N || seven_c1 < 0)
      ans += tar_sand*7 / 100;
    else 
      map[seven_r1][seven_c1] += tar_sand*7 / 100;

    if(seven_r2 >= N || seven_r2 < 0 || seven_c2 >= N || seven_c2 < 0)
      ans += tar_sand*7 / 100;
    else
      map[seven_r2][seven_c2] += tar_sand*7 / 100;

    // 10%
    int ten_r1 = tornado_r + 1;
    int ten_c1 = tornado_c - 1;
    int ten_r2 = tornado_r + 1;
    int ten_c2 = tornado_c + 1;

    remain_sand -= tar_sand*10 / 100;
    remain_sand -= tar_sand*10 / 100;

    if(ten_r1 >= N || ten_r1 < 0 || ten_c1 >= N || ten_c1 < 0)
      ans += tar_sand*10 / 100;
    else 
      map[ten_r1][ten_c1] += tar_sand*10 / 100;

    if(ten_r2 >= N || ten_r2 < 0 || ten_c2 >= N || ten_c2 < 0)
      ans += tar_sand*10 / 100;
    else
      map[ten_r2][ten_c2] += tar_sand*10 / 100;

    // alpha
    int alpha_r = tornado_r + 1;
    int alpha_c = tornado_c;

    if(alpha_r >= N || alpha_r < 0 || alpha_c >= N || alpha_c < 0)
      ans += remain_sand;
    else
      map[alpha_r][alpha_c] += remain_sand;
  }
  else if(cur_dir == 2){ // 동
    // 1%
    int one_r1 = tornado_r - 1;
    int one_c1 = tornado_c - 1;
    int one_r2 = tornado_r + 1;
    int one_c2 = tornado_c - 1;

    remain_sand -= tar_sand / 100;
    remain_sand -= tar_sand / 100;

    if(one_r1 >= N || one_r1 < 0 || one_c1 >= N || one_c1 < 0)
      ans += tar_sand / 100;
    else 
      map[one_r1][one_c1] += tar_sand / 100;

    if(one_r2 >= N || one_r2 < 0 || one_c2 >= N || one_c2 < 0)
      ans += tar_sand / 100;
    else
      map[one_r2][one_c2] += tar_sand / 100;

    // 2%
    int two_r1 = tornado_r - 2;
    int two_c1 = tornado_c;
    int two_r2 = tornado_r + 2;
    int two_c2 = tornado_c;

    remain_sand -= tar_sand*2 / 100;
    remain_sand -= tar_sand*2 / 100;

    if(two_r1 >= N || two_r1 < 0 || two_c1 >= N || two_c1 < 0)
      ans += tar_sand*2 / 100;
    else 
      map[two_r1][two_c1] += tar_sand*2 / 100;

    if(two_r2 >= N || two_r2 < 0 || two_c2 >= N || two_c2 < 0)
      ans += tar_sand*2 / 100;
    else
      map[two_r2][two_c2] += tar_sand*2 / 100;
 
    // 5%
    int five_r = tornado_r;
    int five_c = tornado_c + 2;

    remain_sand -= tar_sand*5 / 100;
    
    if(five_r >= N || five_r < 0 || five_c >= N || five_c < 0)
      ans += tar_sand*5 / 100;
    else
      map[five_r][five_c] += tar_sand*5 / 100;

    // 7%
    int seven_r1 = tornado_r - 1;
    int seven_c1 = tornado_c;
    int seven_r2 = tornado_r + 1;
    int seven_c2 = tornado_c;

    remain_sand -= tar_sand*7 / 100;
    remain_sand -= tar_sand*7 / 100;

    if(seven_r1 >= N || seven_r1 < 0 || seven_c1 >= N || seven_c1 < 0)
      ans += tar_sand*7 / 100;
    else 
      map[seven_r1][seven_c1] += tar_sand*7 / 100;

    if(seven_r2 >= N || seven_r2 < 0 || seven_c2 >= N || seven_c2 < 0)
      ans += tar_sand*7 / 100;
    else
      map[seven_r2][seven_c2] += tar_sand*7 / 100;

    // 10%
    int ten_r1 = tornado_r + 1;
    int ten_c1 = tornado_c + 1;
    int ten_r2 = tornado_r - 1;
    int ten_c2 = tornado_c + 1;

    remain_sand -= tar_sand*10 / 100;
    remain_sand -= tar_sand*10 / 100;

    if(ten_r1 >= N || ten_r1 < 0 || ten_c1 >= N || ten_c1 < 0)
      ans += tar_sand*10 / 100;
    else 
      map[ten_r1][ten_c1] += tar_sand*10 / 100;

    if(ten_r2 >= N || ten_r2 < 0 || ten_c2 >= N || ten_c2 < 0)
      ans += tar_sand*10 / 100;
    else
      map[ten_r2][ten_c2] += tar_sand*10 / 100;

    // alpha
    int alpha_r = tornado_r;
    int alpha_c = tornado_c + 1;

    if(alpha_r >= N || alpha_r < 0 || alpha_c >= N || alpha_c < 0)
      ans += remain_sand;
    else
      map[alpha_r][alpha_c] += remain_sand;
  }
  else if(cur_dir == 3){ // 북
    // 1%
    int one_r1 = tornado_r + 1;
    int one_c1 = tornado_c + 1;
    int one_r2 = tornado_r + 1;
    int one_c2 = tornado_c - 1;

    remain_sand -= tar_sand / 100;
    remain_sand -= tar_sand / 100;

    if(one_r1 >= N || one_r1 < 0 || one_c1 >= N || one_c1 < 0)
      ans += tar_sand / 100;
    else 
      map[one_r1][one_c1] += tar_sand / 100;

    if(one_r2 >= N || one_r2 < 0 || one_c2 >= N || one_c2 < 0)
      ans += tar_sand / 100;
    else
      map[one_r2][one_c2] += tar_sand / 100;

    // 2%
    int two_r1 = tornado_r;
    int two_c1 = tornado_c - 2;
    int two_r2 = tornado_r;
    int two_c2 = tornado_c + 2;

    remain_sand -= tar_sand*2 / 100;
    remain_sand -= tar_sand*2 / 100;

    if(two_r1 >= N || two_r1 < 0 || two_c1 >= N || two_c1 < 0)
      ans += tar_sand*2 / 100;
    else 
      map[two_r1][two_c1] += tar_sand*2 / 100;

    if(two_r2 >= N || two_r2 < 0 || two_c2 >= N || two_c2 < 0)
      ans += tar_sand*2 / 100;
    else
      map[two_r2][two_c2] += tar_sand*2 / 100;
 
    // 5%
    int five_r = tornado_r - 2;
    int five_c = tornado_c;

    remain_sand -= tar_sand*5 / 100;
    
    if(five_r >= N || five_r < 0 || five_c >= N || five_c < 0)
      ans += tar_sand*5 / 100;
    else
      map[five_r][five_c] += tar_sand*5 / 100;

    // 7%
    int seven_r1 = tornado_r;
    int seven_c1 = tornado_c - 1;
    int seven_r2 = tornado_r;
    int seven_c2 = tornado_c + 1;

    remain_sand -= tar_sand*7 / 100;
    remain_sand -= tar_sand*7 / 100;

    if(seven_r1 >= N || seven_r1 < 0 || seven_c1 >= N || seven_c1 < 0)
      ans += tar_sand*7 / 100;
    else 
      map[seven_r1][seven_c1] += tar_sand*7 / 100;

    if(seven_r2 >= N || seven_r2 < 0 || seven_c2 >= N || seven_c2 < 0)
      ans += tar_sand*7 / 100;
    else
      map[seven_r2][seven_c2] += tar_sand*7 / 100;

    // 10%
    int ten_r1 = tornado_r - 1;
    int ten_c1 = tornado_c - 1;
    int ten_r2 = tornado_r - 1;
    int ten_c2 = tornado_c + 1;

    remain_sand -= tar_sand*10 / 100;
    remain_sand -= tar_sand*10 / 100;

    if(ten_r1 >= N || ten_r1 < 0 || ten_c1 >= N || ten_c1 < 0)
      ans += tar_sand*10 / 100;
    else 
      map[ten_r1][ten_c1] += tar_sand*10 / 100;

    if(ten_r2 >= N || ten_r2 < 0 || ten_c2 >= N || ten_c2 < 0)
      ans += tar_sand*10 / 100;
    else
      map[ten_r2][ten_c2] += tar_sand*10 / 100;

    // alpha
    int alpha_r = tornado_r - 1;
    int alpha_c = tornado_c;

    if(alpha_r >= N || alpha_r < 0 || alpha_c >= N || alpha_c < 0)
      ans += remain_sand;
    else
      map[alpha_r][alpha_c] += remain_sand;
  }

  return;
}

void solve(){
  while(true){
    //토네이도를 움직인다.
    move_tornado();
  
    // 해당 위치에 있는 모래를 알고리즘에 따라 움직인다. (나가는 모래까지 측정)
    move_sand();

    if(tornado_r == 0 && tornado_c == 0)
      break;
  }

  return;
}

int main(){
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%d", &map[i][j]);
    }
  }

  tornado_r = N/2;
  tornado_c = N/2;

  solve();
  printf("%d\n", ans);

  return 0;
}
