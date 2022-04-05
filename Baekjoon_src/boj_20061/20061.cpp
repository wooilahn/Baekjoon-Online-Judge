#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int red_b[4][4]   = {0};
int blue_b[4][6]  = {0};
int green_b[6][4] = {0};

int score = 0;
int fill_b = 0;
int N;

void check_score() {
	int tmp_score = 0;

	while (true) {
		bool line_flag = false;

		// green
		for (int i = 5; i >= 0; i--) {
			int fill_num_g = 0;

			for (int k = 0; k <= 3; k++) {
				if (green_b[i][k])
					fill_num_g++;
			}

			if (fill_num_g == 4) {
				line_flag = true;

				for (int k = 0; k <= 3; k++) {
					green_b[i][k] = 0;
				}

				for (int r = i - 1; r >= 0; r--) {
					for (int k = 0; k <= 3; k++) {
						green_b[r + 1][k] = green_b[r][k];
						green_b[r][k] = 0;
					}
				}

				break;
			}
		}

		if (line_flag)
			tmp_score++;
		else if (!line_flag)
			break;
	}

	while (true) {
		bool line_flag = false;

		// blue
		for (int i = 5; i >= 0; i--) {
			int fill_num_b = 0;

			for (int k = 0; k <= 3; k++) {
				if (blue_b[k][i])
					fill_num_b++;
			}

			if (fill_num_b == 4) {
				line_flag = true;

				for (int k = 0; k <= 3; k++) {
					blue_b[k][i] = 0;
				}

				for (int r = 0; r <= 3; r++) {
					for (int c = i - 1; c >= 0; c--) {
						blue_b[r][c + 1] = blue_b[r][c];
						blue_b[r][c] = 0;
					}
				}

				break;
			}
		}

		if (line_flag)
			tmp_score++;
		else if (!line_flag)
			break;
	}

	score += tmp_score;
	return;
}

void check_overline() {
	// green
	int over_green = 0;
	for (int i = 0; i <= 1; i++) {
		for (int k = 0; k <= 3; k++) {
			if (green_b[i][k]) {
				over_green++;
				break;
			}
		}
	}

	if (over_green == 1) {
		for (int k = 0; k <= 3; k++)
			green_b[5][k] = 0;

		for (int i = 4; i >= 0; i--) {
			for (int k = 0; k <= 3; k++) {
				green_b[i + 1][k] = green_b[i][k];
				green_b[i][k] = 0;
			}
		}
	}
	else if (over_green == 2) {
		for (int k = 0; k <= 3; k++) {
			green_b[5][k] = 0;
			green_b[4][k] = 0;
		}

		for (int i = 3; i >= 0; i--) {
			for (int k = 0; k <= 3; k++) {
				green_b[i + 2][k] = green_b[i][k];
				green_b[i][k] = 0;
			}
		}
	}

	// blue
	int over_blue = 0;
	for (int i=0; i<=1; i++) {
		for (int k=0; k<=3; k++) {
			if (blue_b[k][i]) {
				over_blue++;
				break;
			}
		}
	}

	if (over_blue == 1) {
		for (int k = 0; k <= 3; k++)
			blue_b[k][5] = 0;

		for (int i = 4; i >= 0; i--) {
			for (int k = 0; k <= 3; k++) {
				blue_b[k][i + 1] = blue_b[k][i];
				blue_b[k][i] = 0;
			}
		}
	}
	else if (over_blue == 2) {
		for (int k = 0; k <= 3; k++) {
			blue_b[k][5] = 0;
			blue_b[k][4] = 0;
		}
		for (int i = 3; i >= 0; i--) {
			for (int k = 0; k <= 3; k++) {
				blue_b[k][i + 2] = blue_b[k][i];
				blue_b[k][i] = 0;
			}
		}
	}

	return;
}

void solve(int type, int x, int y){
  int g_x = -1;
  int g_y = -1;
  int b_x = -1;
  int b_y = -1;

  if(type == 1){ // 1x1
	// Green block (Find x)(Fixed y)
	for(int i=0; i<=5; i++){
	  if(green_b[i][y]){
	    g_x = i-1;
		break;
	  }
	}
	if(g_x == -1)
	  g_x = 5;
	
	g_y = y;
	green_b[g_x][g_y] = 1;

    // Blue block (Find y)(Fixed x)
	for(int i=0; i<=5; i++){
	  if(blue_b[x][i]){
	    b_y = i-1;
		break;
	  }
	}
	if(b_y == -1)
	  b_y = 5;

	  b_x = x;
	  blue_b[b_x][b_y] = 1;
  }
  else if(type == 2){ // 1x2 (horizon)
    // Green block (Find x)(Fixed y)
	for(int i=0; i<=5; i++){
	  if(green_b[i][y] || green_b[i][y+1]){
	    g_x = i-1;
		break;
	  }
	}
	if(g_x == -1)
	  g_x = 5;

	g_y = y;
	green_b[g_x][g_y] = 1;
	green_b[g_x][g_y+1] = 1;

	// Blue block (Find y)(Fixed x)
	for(int i=0; i<=5; i++){
	  if(blue_b[x][i]){
	    b_y = i-1;
		break;
	  }
	}
	if(b_y == -1)
	  b_y = 5;

	b_x = x;
	blue_b[b_x][b_y-1] = 1;
	blue_b[b_x][b_y] = 1;
  }
  else if(type == 3){ // 2x1 (vertical)
    // Green block (Find x)(Fixed y)
	for(int i=0; i<=5; i++){
	  if(green_b[i][y]){
	    g_x = i-1;
		break;
	  }
	}
	if(g_x == -1)
	  g_x = 5;

	g_y = y;
	green_b[g_x][g_y] = 1;
	green_b[g_x-1][g_y] = 1;

	// Blue block (Find y)(Fixed x)
	for(int i=0; i<=5; i++){
	  if(blue_b[x][i] || blue_b[x+1][i]){
	    b_y = i-1;
		break;
	  }
	}
	if(b_y == -1)
	  b_y = 5;

	b_x = x;
	blue_b[b_x][b_y] = 1;
	blue_b[b_x+1][b_y] = 1;
  }

  check_score();
  check_overline();
}

void cal_b(){
  for(int i=0; i<4; i++){
    for(int j=0; j<6; j++){
	  fill_b += blue_b[i][j];
	  fill_b += green_b[j][i];
	}
  }
}

int main(){

  scanf("%d", &N);

  while(N--){
    int t, x, y;
	scanf("%d %d %d", &t, &x, &y);
	solve(t,x,y);
  }

  cal_b();
  printf("%d\n%d\n", score, fill_b);

  return 0;
}
