#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
vector<string> method;
char cube[10][6][6] = {0}; // [dir][r][c]
                          // dir: 0(up, w), 1(down, y), 2(front, r), 3(back, o), 4(left, g), 5(right, b)

char tmp_cube[10][6][6] = {0};

void print_upside(){
	// print up-side of cube
	for (int r = 2; r >= 0; r--) {
		for (int c = 2; c >= 0; c--) {
			cout << cube[0][r][c];
		}
		cout << endl;
	}
	
	return;
}

void move_side(int w_side, char w_sign){
  char tmp_sign = w_sign;

  if(w_side == 1){
    if(tmp_sign == '+')
	  tmp_sign = '-';
	else if(tmp_sign == '-')
	  tmp_sign = '+';
  }

  if(tmp_sign == '+'){
	  // 0,0 -> 0,2
	  // 0,1 -> 1,2
	  // 0,2 -> 2,2
	  tmp_cube[w_side][0][2] = cube[w_side][0][0];
	  tmp_cube[w_side][1][2] = cube[w_side][0][1];
	  tmp_cube[w_side][2][2] = cube[w_side][0][2];

	  // 1,0 -> 0,1
	  // 1,1 -> 1,1
	  // 1,2 -> 2,1
	  tmp_cube[w_side][0][1] = cube[w_side][1][0];
	  tmp_cube[w_side][1][1] = cube[w_side][1][1];
	  tmp_cube[w_side][2][1] = cube[w_side][1][2];

	  // 2,0 -> 0,0
	  // 2,1 -> 1,0
	  // 2,2 -> 2,0
	  tmp_cube[w_side][0][0] = cube[w_side][2][0];
	  tmp_cube[w_side][1][0] = cube[w_side][2][1];
	  tmp_cube[w_side][2][0] = cube[w_side][2][2];
  }
  else if(tmp_sign == '-'){
	  // 0,0 -> 2,0
	  // 0,1 -> 1,0
	  // 0,2 -> 0,0
	  tmp_cube[w_side][2][0] = cube[w_side][0][0];
	  tmp_cube[w_side][1][0] = cube[w_side][0][1];
	  tmp_cube[w_side][0][0] = cube[w_side][0][2];

	  // 1,0 -> 2,1
	  // 1,1 -> 1,1
	  // 1,2 -> 0,1
	  tmp_cube[w_side][2][1] = cube[w_side][1][0];
	  tmp_cube[w_side][1][1] = cube[w_side][1][1];
	  tmp_cube[w_side][0][1] = cube[w_side][1][2];

	  // 2,0 -> 2,2
	  // 2,1 -> 1,2
	  // 2,2 -> 0,2
	  tmp_cube[w_side][2][2] = cube[w_side][2][0];
	  tmp_cube[w_side][1][2] = cube[w_side][2][1];
	  tmp_cube[w_side][0][2] = cube[w_side][2][2];
  }

  for(int r=0; r<3; r++){
    for(int c=0; c<3; c++){
	  cube[w_side][r][c] = tmp_cube[w_side][r][c];
	}
  }

  return;
}

void move_cube(char side, char sign){
  memset(tmp_cube, 0, sizeof(tmp_cube));
  
  // 한면만 이동
  if(side == 'U'){ // 윗면 => (2, 3, 4, 5 변경)
    if(sign == '+'){ 
	  for(int i=0; i<3; i++){
		// front 1번째 가로줄 -> left 1번째 가로줄
	    tmp_cube[4][0][i] = cube[2][0][i];
		// left 1번째 가로줄 -> back 1번째 가로줄
		tmp_cube[3][0][i] = cube[4][0][i];
		// back 1번째 가로줄 -> right 1번째 가로줄
		tmp_cube[5][0][i] = cube[3][0][i];
		// right 1번째 가로줄 -> front 1번째 가로줄
		tmp_cube[2][0][i] = cube[5][0][i];
	  }
	}
	else if(sign == '-'){ 
	  for(int i=0; i<3; i++){
		// left 1번째 가로줄 -> front 1번째 가로줄
		tmp_cube[2][0][i] = cube[4][0][i];
		// front 1번째 가로줄 -> right 1번째 가로줄
		tmp_cube[5][0][i] = cube[2][0][i];
		// right 1번째 가로줄 -> back 1번째 가로줄
		tmp_cube[3][0][i] = cube[5][0][i];
		// back 1번째 가로줄 -> left 1번째 가로줄
		tmp_cube[4][0][i] = cube[3][0][i];
	  }
	}

	move_side(0, sign);
	for (int i = 0; i < 3; i++) {
		cube[2][0][i] = tmp_cube[2][0][i]; // front 1번째 가로줄
		cube[3][0][i] = tmp_cube[3][0][i]; // back 1번째 가로줄
		cube[4][0][i] = tmp_cube[4][0][i]; // left 1번째 가로줄
		cube[5][0][i] = tmp_cube[5][0][i]; // right 1번째 가로줄
	}
  }
  else if(side == 'D'){ // 아랫면 (2, 3, 4, 5 변경)
    if(sign == '+'){
		for (int i = 0; i < 3; i++) {
		    // right 3번째 가로줄 -> back 3번째 가로줄
			tmp_cube[3][2][i] = cube[5][2][i];
		    // back 3번째 가로줄 -> left 3번째 가로줄
			tmp_cube[4][2][i] = cube[3][2][i];
		    // left 3번째 가로줄 -> front 3번째 가로줄
			tmp_cube[2][2][i] = cube[4][2][i];
		    // front 3번째 가로줄 -> right 3번째 가로줄
			tmp_cube[5][2][i] = cube[2][2][i];
		}
	}
	else if(sign == '-'){
	    for (int i = 0; i < 3; i++) {
			// back 3번째 가로줄 -> right 3번째 가로줄
			tmp_cube[5][2][i] = cube[3][2][i];
			// right 3번째 가로줄 -> front 3번째 가로줄
			tmp_cube[2][2][i] = cube[5][2][i];
			// front 3번째 가로줄 -> left 3번째 가로줄
			tmp_cube[4][2][i] = cube[2][2][i];
			// left 3번째 가로줄 -> back 3번째 가로줄
			tmp_cube[3][2][i] = cube[4][2][i];
		}
	}

	move_side(1, sign);
	for (int i = 0; i < 3; i++) {
		cube[2][2][i] = tmp_cube[2][2][i]; // front 3번째 가로줄
		cube[3][2][i] = tmp_cube[3][2][i]; // back 3번째 가로줄
		cube[4][2][i] = tmp_cube[4][2][i]; // left 3번째 가로줄
		cube[5][2][i] = tmp_cube[5][2][i]; // right 3번째 가로줄
	}
  }
  else if(side == 'F'){ // 앞면 (0, 1, 4, 5 변경)
    if(sign == '+'){
	  for(int i=0; i<3; i++){
		// left 3번째 세로줄 -> up 1번째 가로줄
	    tmp_cube[0][0][i] = cube[4][i][2];
		// up 1번째 가로줄 -> right 1번째 세로줄
		tmp_cube[5][2-i][0] = cube[0][0][i];
		// right 1번째 세로줄 -> down 1번째 가로줄
		tmp_cube[1][0][i] = cube[5][i][0];
		// down 1번째 가로줄 -> left 3번째 세로줄
		tmp_cube[4][2-i][2] = cube[1][0][i];
	  }
	}
	else if(sign == '-'){
	  for(int i=0; i<3; i++){
		// up 1번째 가로줄 -> left 3번째 세로줄
		tmp_cube[4][i][2] = cube[0][0][i];
		// left 3번째 세로줄 -> down 1번째 가로줄
		tmp_cube[1][0][2-i] = cube[4][i][2];
		// down 1번째 가로줄 -> right 1번째 세로줄
		tmp_cube[5][i][0] = cube[1][0][i];
		// right 1번째 세로줄 -> up 1번째 가로줄
		tmp_cube[0][0][2-i] = cube[5][i][0];
	  }
	}

	move_side(2, sign);
	for(int i=0; i<3; i++){
	  cube[0][0][i] = tmp_cube[0][0][i]; // up 1번째 가로줄
	  cube[1][0][i] = tmp_cube[1][0][i]; // down 1번째 가로줄
	  cube[4][i][2] = tmp_cube[4][i][2]; // left 3번째 세로줄
	  cube[5][i][0] = tmp_cube[5][i][0]; // right 1번째 세로줄
	}
  }
  else if(side == 'B'){ // 뒷면 (0, 1, 4, 5 변경)
    if(sign == '+'){ 
	  for(int i=0; i<3; i++){
		// up 3번째 가로줄 -> left 1번째 세로줄
	    tmp_cube[4][i][0] = cube[0][2][i];
		// left 1번째 세로줄 -> down 3번째 가로줄
		tmp_cube[1][2][2-i] = cube[4][i][0];
		// down 3번째 가로줄 -> right 3번째 세로줄
		tmp_cube[5][i][2] = cube[1][2][i];
		// right 3번째 세로줄 -> up 3번째 가로줄
		tmp_cube[0][2][2-i] = cube[5][i][2];
	  } 
	}
	else if(sign == '-'){ 
      for(int i=0; i<3; i++){
		// up 3번째 가로줄 -> right 3번째 세로줄
		tmp_cube[5][2-i][2] = cube[0][2][i];
		// right 3번째 세로줄 -> down 3번째 가로줄
		tmp_cube[1][2][i] = cube[5][i][2];
		// down 3번째 가로줄 -> left 1번째 세로줄
		tmp_cube[4][2-i][0] = cube[1][2][i];
		// left 1번째 세로줄 -> up 3번째 가로줄
		tmp_cube[0][2][i] = cube[4][i][0];
	  }
	}

	move_side(3, sign);
	for(int i=0; i<3; i++){
	  cube[0][2][i] = tmp_cube[0][2][i]; // up 3번째 가로줄
	  cube[1][2][i] = tmp_cube[1][2][i]; // down 3번째 가로줄
	  cube[4][i][0] = tmp_cube[4][i][0]; // left 1번째 세로줄
	  cube[5][i][2] = tmp_cube[5][i][2]; // right 3번째 세로줄
	}
  }
  else if(side == 'L'){ // 왼쪽면 (0, 1, 2, 3 변경)
    if(sign == '+'){ 
	  for(int i=0; i<3; i++){
		// up 3번째 세로줄 -> front 1번째 세로줄
	    tmp_cube[2][2-i][0] = cube[0][i][2];
		// front 1번째 세로줄 -> down 3번째 세로줄
		tmp_cube[1][i][2] = cube[2][i][0];
		// down 3번째 세로줄 -> back 3번째 세로줄
		tmp_cube[3][2-i][2] = cube[1][i][2];
		// back 3번째 세로줄 -> up 3번째 세로줄
		tmp_cube[0][i][2] = cube[3][i][2];
	  }
	}
	else if(sign == '-'){ 
	  for(int i=0; i<3; i++){
		// up 3번째 세로줄 -> back 3번째 세로줄
		tmp_cube[3][i][2] = cube[0][i][2];
		// back 3번째 세로줄 -> down 3번째 세로줄
		tmp_cube[1][2-i][2] = cube[3][i][2];
		// down 3번째 세로줄 -> front 1번째 세로줄
		tmp_cube[2][i][0] = cube[1][i][2];
		// front 1번째 세로줄 -> up 3번째 세로줄
		tmp_cube[0][2-i][2] = cube[2][i][0];
	  }
	}

	move_side(4, sign);
	for(int i=0; i<3; i++){
	  cube[0][i][2] = tmp_cube[0][i][2]; // up 3번째 세로줄
	  cube[1][i][2] = tmp_cube[1][i][2]; // down 3번째 세로줄
	  cube[2][i][0] = tmp_cube[2][i][0]; // front 1번째 세로줄
	  cube[3][i][2] = tmp_cube[3][i][2]; // back 3번째 세로줄
	}
  }
  else if(side == 'R'){ // 오른쪽면 (0, 1, 2, 3 변경)
    if(sign == '+'){
	  for(int i=0; i<3; i++){
		// up 1번째 세로줄 -> back 1번째 세로줄
		tmp_cube[3][i][0] = cube[0][i][0];
		// back 1번째 세로줄 -> down 1번째 세로줄
		tmp_cube[1][2-i][0] = cube[3][i][0];
		// down 1번째 세로줄 -> front 3번째 세로줄
		tmp_cube[2][i][2] = cube[1][i][0];
		// front 3번째 세로줄 -> up 1번째 세로줄
		tmp_cube[0][2-i][0] = cube[2][i][2];
	  }
	}
	else if(sign == '-'){
	  for(int i=0; i<3; i++){
		// up 1번째 세로줄 -> front 3번째 세로줄
	    tmp_cube[2][2-i][2] = cube[0][i][0];
		// front 3번째 세로줄 -> down 1번째 세로줄
		tmp_cube[1][i][0] = cube[2][i][2];
		// down 1번째 세로줄 -> back 1번째 세로줄
		tmp_cube[3][2-i][0] = cube[1][i][0];
		// back 1번째 세로줄 -> up 1번째 세로줄
		tmp_cube[0][i][0] = cube[3][i][0];
	  }
	}

	move_side(5, sign);
	for(int i=0; i<3; i++){
	  cube[0][i][0] = tmp_cube[0][i][0]; // up 1번째 세로줄
	  cube[1][i][0] = tmp_cube[1][i][0]; // down 1번째 세로줄
	  cube[2][i][2] = tmp_cube[2][i][2]; // front 3번째 세로줄
	  cube[3][i][0] = tmp_cube[3][i][0]; // back 1번째 세로줄
	}
  }

  return;
}

void solve(){

  for(int i=0; i<method.size(); i++){
    char tar_side = method[i].at(0);
	char tar_sign = method[i].at(1);
	move_cube(tar_side, tar_sign);
  }

  print_upside();
  return;
}

void init_cube(){
  for(int r=0; r<3; r++){
    for(int c=0; c<3; c++){
	  cube[0][r][c] = 'w'; // 윗면
	  cube[1][r][c] = 'y'; // 아랫면
	  cube[2][r][c] = 'r'; // 앞면
	  cube[3][r][c] = 'o'; // 뒷면
	  cube[4][r][c] = 'g'; // 왼쪽면
	  cube[5][r][c] = 'b'; // 오른쪽면
	}
  }

  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){
    int n;
	cin >> n;

	string s;
	init_cube();
	method.clear();
	for(int i=0; i<n; i++){
	  cin >> s;
	  method.push_back(s);
	}

	solve();
  }

  return 0;
}
