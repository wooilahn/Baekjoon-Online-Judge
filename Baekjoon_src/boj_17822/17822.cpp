#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> plate[52];
vector<pair<int,int> > del_v;

int main(){
  int N, M, T;
  int X, D, K;
  int num;

  scanf("%d %d %d", &N, &M, &T);

  for(int i=1; i<=N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &num);
      plate[i].push_back(num);
    }
  }

  while(T--){
    scanf("%d %d %d", &X, &D, &K);

    for(int i=1; i<=N; i++){
      if(i%X != 0)
        continue;

      vector<int> tmp_v;
      tmp_v.resize(plate[i].size());

      // 이동하기
      for(int m=0; m<plate[i].size(); m++){
        int target = plate[i].at(m);
        int cur_idx = m;

        if(D == 0){ // 시계 방향
          cur_idx += K;
          cur_idx %= M;
        }
        else if(D == 1){ // 반시계 방향
          cur_idx -= K;
          
          if(cur_idx < 0){
            cur_idx = -cur_idx;
            cur_idx = M-cur_idx;
          }
        }

        tmp_v[cur_idx] = target;
      }

      for(int m=0; m<plate[i].size(); m++){
        plate[i].at(m) = tmp_v[m];
      }
    }

    // 삭제하기
    bool del_flag = false;
    del_v.clear();

    for(int i=1; i<=N; i++) {
      for(int j=0; j<M; j++) {
        if(j==0){
          if(plate[i][j] == plate[i][M-1]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i, M-1));
            if(plate[i][j] != 0 && plate[i][M-1] != 0)
              del_flag = true;
          }
          if(plate[i][j] == plate[i][1]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i, 1));
            if(plate[i][j] != 0 && plate[i][1] != 0)
              del_flag = true;
          }
        }
        else if(j == M-1){
          if(plate[i][j] == plate[i][M-2]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i, M-2));
            if(plate[i][j] != 0 && plate[i][M-2] != 0)
               del_flag = true;
          }
          if(plate[i][j] == plate[i][0]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i, 0));
            if(plate[i][j] != 0 && plate[i][0] != 0)
               del_flag = true;
          }
        }
        else if(j > 0 && j < M-1){
          if(plate[i][j] == plate[i][j-1]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i, j-1));
            if(plate[i][j] != 0 && plate[i][j-1] != 0)
               del_flag = true;
          }
          else if(plate[i][j] == plate[i][j+1]){
            del_v.push_back(make_pair(i,j));
            del_v.push_back(make_pair(i, j+1));
            if(plate[i][j] != 0 && plate[i][j+1] != 0)
               del_flag = true;
          }
        }

        if(i == 1){
          if(plate[i][j] == plate[2][j]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(2, j));
            if(plate[i][j] != 0 && plate[2][j] != 0)
               del_flag = true;
          }
        }
        else if(i == N){
          if(plate[i][j] == plate[N-1][j]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(N-1, j));
            if(plate[i][j] != 0 && plate[N-1][j] != 0)
               del_flag = true;
          }
        }
        else if(i >= 2 && i<= N-1){
          if(plate[i][j] == plate[i+1][j]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i+1, j));
            if(plate[i][j] != 0 && plate[i+1][j] != 0)
               del_flag = true;
          }
          if(plate[i][j] == plate[i-1][j]){
            del_v.push_back(make_pair(i, j));
            del_v.push_back(make_pair(i-1, j));
            if(plate[i][j] != 0 && plate[i-1][j] != 0)
               del_flag = true;
          }
        }
      }
    }

    if(del_flag){
      for(int i=0; i<del_v.size(); i++){
        plate[del_v[i].first].at(del_v[i].second) = 0;
      }
    }
    else if(!del_flag){
      int up_v = 0;
      int down_v = 0;

      for(int i=1; i<=N; i++){
        for(int j=0; j<plate[i].size(); j++){
          if(plate[i].at(j) != 0){
            up_v += plate[i].at(j);
            down_v += 1;
          }
        }
      }

      double avg = (double)up_v / (double)down_v;

      for(int i=1; i<=N; i++){
        for(int j=0; j<plate[i].size(); j++){
          if(plate[i].at(j) != 0){
            if(avg > (double)plate[i].at(j)){
              plate[i].at(j) = plate[i].at(j) + 1;
            }
            else if(avg < (double)plate[i].at(j)){
              plate[i].at(j) = plate[i].at(j) - 1;
            }
          }
        }
      }
    }
  }

  int ans = 0;

  for(int i=1; i<=N; i++){
    for(int j=0; j<plate[i].size(); j++){
      ans += plate[i].at(j);
    }
  }

  printf("%d\n", ans);

  return 0;
}
