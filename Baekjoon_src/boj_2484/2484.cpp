#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int dice[7] = {0};

int main(){
  int N, ans = 0;
  scanf("%d", &N);
  
  while(N--){
    int sum = 0;
	int num = 0;
	memset(dice, 0, sizeof(dice));

	for(int k=0; k<4; k++){
	  scanf("%d", &num);
	  dice[num]++;
	}

	bool find_flag = false;

	for(int i=1; i<=6; i++){
	  if(dice[i] == 4){
	    sum = 50000 + i*5000;
		find_flag = true;
		break;
	  }
	  else if(dice[i] == 3){
	    sum = 10000 + i*1000;
		find_flag = true;
		break;
	  }
	}

	if(!find_flag){
	  int n_twice = 0;
	  int t1, t2;
	  int max_v = -1;

	  for(int i=1; i<=6; i++){
	    if(dice[i] == 2){
		  if(n_twice == 0)
		    t1 = i;
		  else if(n_twice == 1)
		    t2 = i;
		  n_twice++;
		}
		if(dice[i] == 1)
		  max_v = i;
	  }

	  if(n_twice == 0)
	    sum = max_v * 100;
	  else if(n_twice == 1)
	    sum = 1000 + t1*100;
	  else if(n_twice == 2)
	    sum = 2000+ t1*500 + t2*500;
	}

	ans = max(ans, sum);
  }

  printf("%d\n", ans);

  return 0;
}
