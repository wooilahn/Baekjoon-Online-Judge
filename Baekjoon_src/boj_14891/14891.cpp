#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char str[4][12] = {0};
int gear[4][12] = {0};

int main(){
  for(int i=0; i<4; i++){
    scanf("%s", str[i]); // 0~7 
	// gear1: 2
	// gear2: 2, 6
	// gear3: 2, 6
	// gear4: 6
	// N: 0, S: 1

	for(int k=0; k<8; k++){
	  if(str[i][k] == '0')
	    gear[i][k] = 0;
	  else if(str[i][k] == '1')
	    gear[i][k] = 1;
	}
  }

  int k;
  scanf("%d", &k);

  while(k--){
    int num, dir;
	scanf("%d %d", &num, &dir);
	int rotate[4] = {0};
	memset(rotate, 0, sizeof(rotate));

	rotate[num-1] = dir;

	if(num == 1){ // gear 1
		if (gear[0][2] != gear[1][6])
			rotate[1] = rotate[0] * -1;
		else
			rotate[1] = 0;

		if (rotate[1] != 0) {
		  if(gear[1][2] != gear[2][6])
		    rotate[2] = rotate[1] * -1;
		  else
		    rotate[2] = 0;
		}

		if(rotate[2] != 0) {
		  if(gear[2][2] != gear[3][6])
		    rotate[3] = rotate[2] * -1;
		  else
		    rotate[3] = 0;
		}
	}
	else if(num == 2){ // gear 2
	  if (gear[0][2] != gear[1][6])
	    rotate[0] = rotate[1] * -1;
	  else
	    rotate[0] = 0;
	
	  if(gear[1][2] != gear[2][6])
	    rotate[2] = rotate[1] * -1;
	  else
	   rotate[2] = 0;

	  if(rotate[2] != 0){
	    if(gear[2][2] != gear[3][6])
		  rotate[3] = rotate[2] * -1;
	    else
		  rotate[3] = 0;
	  }
	}
	else if(num == 3){ // gear 3
	  if (gear[1][2] != gear[2][6])
	    rotate[1] = rotate[2] * -1;
	  else
	    rotate[1] = 0;

	  if (gear[2][2] != gear[3][6])
	    rotate[3] = rotate[2] * -1;
	  else
	    rotate[3] = 0;

	  if(rotate[1] != 0){
	    if(gear[0][2] != gear[1][6])
		  rotate[0] = rotate[1] * -1;
		else
		  rotate[0] = 0;
	  }
	}
	else if(num == 4){ // gear 4
	  if(gear[2][2] != gear[3][6])
	    rotate[2] = rotate[3] * -1;
	  else
	    rotate[2] = 0;

	  if(rotate[2] != 0){
	    if(gear[1][2] != gear[2][6])
		  rotate[1] = rotate[2] * -1;
	    else
		  rotate[1] = 0;
	  }

	  if(rotate[1] != 0){
	    if(gear[0][2] != gear[1][6])
		  rotate[0] = rotate[1] * -1;
		else
		  rotate[0] = 0;
	  }
	}

	for(int i=0; i<4; i++){
	  if (rotate[i] == 0)
		continue;
	  
	  int tmp[10] = {0};

	  for(int a=0; a<8; a++)
	    tmp[a] = gear[i][a];

	  if(rotate[i] == 1){ // clockwise
	    gear[i][0] = tmp[7];

		for(int a=1; a<8; a++)
		  gear[i][a] = tmp[a-1];
	  }
	  else if(rotate[i] == -1){ // counter-clockwise
	    gear[i][7] = tmp[0];

		for(int a=0; a<=6; a++)
		  gear[i][a] = tmp[a+1];
	  }
	}
  }

  int ans = 0;

  if(gear[0][0] == 1)
    ans += 1;
  if(gear[1][0] == 1)
    ans += 2;
  if(gear[2][0] == 1)
    ans += 4;
  if(gear[3][0] == 1)
    ans += 8;


  printf("%d\n", ans);

  return 0;
}
