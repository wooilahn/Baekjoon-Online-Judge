#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

char map[105][105] = {0};

int main(){
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; i++)
    scanf("%s", map[i]);

  int horizon_cnt = 0;
  int vertical_cnt = 0;

  for(int i=0; i<N; i++){
    int cur_cnt = 0;

    for(int k=0; k<N; k++){
	  if(map[i][k] == '.')
	    cur_cnt++;
	  if(map[i][k] == 'X')
	    cur_cnt = 0;

	  if(cur_cnt >= 2){
	    horizon_cnt++;

		while (map[i][k] == '.')
			k++;
		k--;
	  }
	}

	cur_cnt = 0;
	for(int k=0; k<N; k++){
	  if(map[k][i] == '.')
	    cur_cnt++;
	  if(map[k][i] == 'X')
	    cur_cnt = 0;
	  
	  if(cur_cnt >= 2){
	    vertical_cnt++;
		
		while(map[k][i] == '.')
		  k++;
		k--;
	  }
	}
  }

  printf("%d %d\n", horizon_cnt, vertical_cnt);

  return 0;
}
