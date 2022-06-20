#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int R, C;
int ans = 0;
char str[505] = {0};
int map[10005][505] = {0};

int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool solve(int cur_r, int cur_c){
  if(cur_c == C-1){
    ans++;
	return true;
  }

  map[cur_r][cur_c] = 1;

  for(int i=0; i<3; i++){
    int tmp_r = cur_r + dx[i];
	int tmp_c = cur_c + dy[i];

	if(tmp_r < 0 || tmp_r >= R || tmp_c < 0 || tmp_c >= C)
	  continue;
	if(map[tmp_r][tmp_c] == 1)
	  continue;

	if(solve(tmp_r, tmp_c))
	  return true;
  }

  return false;
}

int main(){
  scanf("%d %d", &R, &C);

  for(int i=0; i<R; i++){
    scanf("%s", str);

	for(int k=0; k<C; k++){
	  if(str[k] == '.')
	    map[i][k] = 0;
	  else if(str[k] == 'x')
	    map[i][k] = 1;
	}
  }
  
  for(int i=0; i<R; i++){
    bool find_route = solve(i, 0);
  }

  printf("%d\n", ans);
  return 0;
}
