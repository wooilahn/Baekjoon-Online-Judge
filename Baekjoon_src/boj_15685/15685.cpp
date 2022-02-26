#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int map[105][105] = {0};
vector<int> dir_v;

int main(){
  int N;
  scanf("%d", &N);

  while(N--){
    int x, y, d, g;
    scanf("%d %d %d %d", &x, &y, &d, &g);
    dir_v.clear();

    // original: 0: right, 1: up, 2: left, 3: down
    // 90 angle: 1: up, 2: left, 3: down, 0: right
    dir_v.push_back(d);

    for(int i=1; i<=g; i++){
      int v_size = dir_v.size();
      vector<int> tmp_v;

      for(int k=v_size-1; k>=0; k--){
        int target_dir = dir_v[k];

        if(target_dir == 0)
          tmp_v.push_back(1);
        else if(target_dir == 1)
          tmp_v.push_back(2);
        else if(target_dir == 2)
          tmp_v.push_back(3);
        else if(target_dir == 3)
          tmp_v.push_back(0);
      }

      for(int k=0; k<tmp_v.size(); k++){
        dir_v.push_back(tmp_v[k]);
      }
    }
    
    int cur_x = x;
    int cur_y = y;
    map[cur_y][cur_x] = 1;

    for(int k=0; k<dir_v.size(); k++){
      int cur_dir = dir_v[k];

      if(cur_dir == 0){ // right
        cur_x += 1;
        map[cur_y][cur_x] = 1;
      }
      else if(cur_dir == 1){ // up
        cur_y -= 1;
        map[cur_y][cur_x] = 1;
      }
      else if(cur_dir == 2){ // left
        cur_x -= 1;
        map[cur_y][cur_x] = 1;
      }
      else if(cur_dir == 3){ // down
        cur_y += 1;
        map[cur_y][cur_x] = 1;
      }
    }
  }

  int ans = 0;

  for(int i=0; i<=100; i++){
    for(int j=0; j<= 100; j++){
      int v_cnt = 0;

      if(map[i][j])
        v_cnt++;
      if(map[i+1][j+1])
        v_cnt++;
      if(map[i+1][j])
        v_cnt++;
      if(map[i][j+1])
        v_cnt++;
      
      if(v_cnt == 4)
        ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
