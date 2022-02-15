#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int map[55][55] = {0};
queue< pair<pair<int,int>,int> > q;
int chk[55][55] = {0};

int main(){
  int answer = 0;
  int N, M;
  int r, c, d;
  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);

  for(int i=0; i<55; i++){
    for(int j=0; j<55; j++){
      map[i][j] = 1;
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &map[i][j]);
    }
  }

  q.push(make_pair(make_pair(r, c), d));

  while(!q.empty()){
    int cur_r, cur_c, cur_d;
    cur_r = q.front().first.first;
    cur_c = q.front().first.second;
    cur_d = q.front().second;
    q.pop();

    if(chk[cur_r][cur_c] == 0 && map[cur_r][cur_c] == 0){
      chk[cur_r][cur_c]++;
      answer++;
    }

    // 0 north -> 3 west
    // 1 east -> 0 north
    // 2 south -> 1 east 
    // 3 west -> 2 south
    int ori_d = cur_d;
    bool save_flag = false;

    for(int i=0; i<4; i++){
      if(cur_d == 0)
        cur_d = 3;
      else
        cur_d = cur_d - 1;

      if(cur_d == 0 && cur_r-1 >= 0){ // north
        if(chk[cur_r-1][cur_c] == 0 && map[cur_r-1][cur_c] == 0){
          chk[cur_r-1][cur_c]++;
          answer++;
          q.push(make_pair(make_pair(cur_r-1, cur_c), cur_d));
          save_flag = true;
          break;
        }
      }
      else if(cur_d == 1 && cur_c+1 < M){ // east
        if(chk[cur_r][cur_c+1] == 0 && map[cur_r][cur_c+1] == 0){
          chk[cur_r][cur_c+1]++;
          answer++;
          q.push(make_pair(make_pair(cur_r, cur_c+1), cur_d));
          save_flag = true;
          break;
        }
      }
      else if(cur_d == 2 && cur_r+1 < N) { // south
        if(chk[cur_r+1][cur_c] == 0 && map[cur_r+1][cur_c] == 0){
          chk[cur_r+1][cur_c]++;
          answer++;
          q.push(make_pair(make_pair(cur_r+1, cur_c), cur_d));
          save_flag = true;
          break;
        }
      }
      else if(cur_d == 3 && cur_c-1 >= 0) { // west
        if(chk[cur_r][cur_c-1] == 0 && map[cur_r][cur_c-1] == 0){
          chk[cur_r][cur_c-1]++;
          answer++;
          q.push(make_pair(make_pair(cur_r, cur_c-1), cur_d));
          save_flag = true;
          break;
        }
      }
    }

    if(cur_d == ori_d && save_flag == false){
      if(ori_d == 0 && cur_r+1 < N){ // north
        if(map[cur_r+1][cur_c] == 0)
          q.push(make_pair(make_pair(cur_r+1, cur_c), ori_d));
      }
      else if(ori_d == 1 && cur_c-1 >= 0){ // east
        if(map[cur_r][cur_c-1] == 0)
          q.push(make_pair(make_pair(cur_r, cur_c-1), ori_d));
      }
      else if(ori_d == 2 && cur_r-1 >= 0) { // south
        if(map[cur_r-1][cur_c] == 0)
          q.push(make_pair(make_pair(cur_r-1, cur_c), ori_d));
      }
      else if(ori_d == 3 && cur_c+1 < M) { // west
        if(map[cur_r][cur_c+1] == 0)
          q.push(make_pair(make_pair(cur_r, cur_c+1), ori_d));
      }  
    }
  }

  printf("%d\n", answer);
  return 0;
}
