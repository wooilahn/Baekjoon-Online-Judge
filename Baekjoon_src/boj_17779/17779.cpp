#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int map[25][25] = {0};
int check[25][25] = {0};

int main(){
  int N;
  int min_v = 999999999;
  scanf("%d", &N);

  for(int i=1; i<=N; i++){
    for(int j=1; j<= N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  vector<int> p_v;

  for(int y=1; y<=N; y++){
    for(int x=1; x<=N; x++){
	  for(int d1 = 1; d1 <= N; d1++){
	    for(int d2 = 1; d2 <= N; d2++){
		  if(x+d1+d2 > N)
		    continue;
		  if(y-d1 < 1 || y+d2 > N)
		    continue;

		  memset(check, 0, sizeof(check));

		  check[x][y] = 5;

		  for(int i=1; i<=d1; i++){
		    check[x+i][y-i] = 5;
			check[x+d2+i][y+d2-i] = 5;
		  }

		  for(int i=1; i<=d2; i++){
		    check[x+i][y+i] = 5;
			check[x+d1+i][y-d1+i] = 5;
		  }

		  p_v.clear();
		  p_v.resize(5);

		  for(int r=1; r<x+d1; r++){
		    for(int c=1; c<=y; c++){
			  if(check[r][c] == 5)
			    break;
			  else if(check[r][c] == 0)
			    check[r][c] = 1;
			}
		  }

		  for(int r=1; r<=x+d2; r++){
		    for(int c=N; c>y; c--){
			  if(check[r][c] == 5)
			    break;
			  else if(check[r][c] == 0)
			    check[r][c] = 2;
			}
		  }

		  for(int r=N; r>=x+d1; r--){
		    for(int c=1; c<y-d1+d2; c++){
			  if(check[r][c] == 5)
			    break;
			  else if(check[r][c] == 0)
			    check[r][c] = 3;
			}
		  }

		  for(int r=N; r>x+d2; r--){
		    for(int c=N; c>=y-d1+d2; c--){
			  if(check[r][c] == 5)
			    break;
			  else if(check[r][c] == 0)
			    check[r][c] = 4;
			}
		  }

		  
		  for(int r=1; r<=N; r++){
		    for(int c=1; c<=N; c++){
			  if(check[r][c] == 0)
			    check[r][c] = 5;
			}
		  }
		  

		  for(int r=1; r<=N; r++){
		    for(int c=1; c<=N; c++){
			  p_v[check[r][c]-1] += map[r][c];
			}
		  }

		  sort(p_v.begin(), p_v.end());
		  min_v = min(min_v, p_v[4] - p_v[0]);
		}
	  }
	}
  }

  printf("%d\n", min_v);
  return 0;
}
