#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct shark{
  int s; // velocity
  int d; // direction
  int z; // size
}Shark;

vector<shark> map[105][105];


int main(){
  int R, C, M;
  scanf("%d %d %d", &R, &C, &M);

  if(M==0){
    printf("0\n");
	return 0;
  }

  int ans = 0;

  for(int i=0; i<M; i++){
	int r, c, s, d, z;
    scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
	shark sh;

	sh.s = s;
	sh.d = d; // 1:up, 2:down, 3:right, 4:left
	sh.z = z;

	map[r-1][c-1].push_back(sh);
  }

  for(int i=0; i<C; i++){
    // 1. catch the shark
	for(int k=0; k<R; k++){
	  if(map[k][i].size() > 0){
		ans += map[k][i].at(0).z;
	    map[k][i].pop_back();
		break;
	  }
	}

	// 2. move the shark
	vector<shark> tmp_map[105][105];

	for(int x=0; x<R; x++){
	  for(int y=0; y<C; y++){
	    if(map[x][y].size() > 0){
		  int vel = map[x][y].at(0).s;
		  int dir = map[x][y].at(0).d;
		  int size = map[x][y].at(0).z;
		  int cur_x = x;
		  int cur_y = y;
		  int final_dir = dir;

		  for(int k=0; k<vel; k++){
			  if (final_dir == 1) { // up
			    if(cur_x == 0){
				  final_dir = 2;
				  cur_x++;
				}
				else
					cur_x--;
			  }
			  else if (final_dir == 2) { // down
				if(cur_x == R-1){
				  final_dir = 1;
				  cur_x--;
				}
				else
				  cur_x++;
			  }
			  else if (final_dir == 3) { // right
				if(cur_y == C-1){
				  final_dir = 4;
				  cur_y--;
				}
				else
				  cur_y++;
			  }
			  else if (final_dir == 4) { // left
				if(cur_y == 0){
				  final_dir = 3;
				  cur_y++;
				}
				else
				  cur_y--;
			  }
		  }
		  
		  shark tmp_sh;
		  tmp_sh.s = vel;
		  tmp_sh.d = final_dir;
		  tmp_sh.z = size;
		  tmp_map[cur_x][cur_y].push_back(tmp_sh);

		  // 이미 상어가 있다면 크기 비교
		  if(tmp_map[cur_x][cur_y].size() > 1){
		    int max_size = -1;

			for(int k=0; k<tmp_map[cur_x][cur_y].size(); k++){
			  if(tmp_map[cur_x][cur_y].at(k).z > max_size)
			    max_size = tmp_map[cur_x][cur_y].at(k).z;
			}

			for(int k=0; k<tmp_map[cur_x][cur_y].size(); k++){
			  if(max_size > tmp_map[cur_x][cur_y].at(k).z)
			    tmp_map[cur_x][cur_y].erase(tmp_map[cur_x][cur_y].begin() + k);
			}
		  }
		}
	  }
	}

	for(int x=0; x<R; x++){
	 for(int y=0; y<C; y++){
	   map[x][y].clear();

	   for(int k=0; k<tmp_map[x][y].size(); k++){
	     map[x][y].push_back(tmp_map[x][y].at(k));
	   }
	 }
	}
  }

  printf("%d\n", ans);
  return 0;
}
