#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int R, C, K;
int W;

vector<pair<pair<int,int>, int>> walls;
vector<pair<int,int>> right_fan; // 1 (오른쪽으로) c++
vector<pair<int,int>> left_fan;  // 2 (왼쪽으로)   c--
vector<pair<int,int>> up_fan;    // 3 (위쪽으로)   r--
vector<pair<int,int>> down_fan;  // 4 (아래쪽으로) r++
vector<pair<int,int>> investigate_space; // 5

int map[25][25] = { 0 };
int wall_map[25][25][5] = { 0 }; // 1:오른쪽, 2:왼쪽, 3:위쪽, 4:아래쪽
int temp_map[25][25] = {0};
int tmp_map[25][25] = {0};
int add_map[25][25] = {0};
int adjust_map[25][25] = {0};
int eaten_chocolate = 0;

int dw[3] = {-1, 0, 1};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void add_temp_map(){
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
	  temp_map[i][j] += add_map[i][j];
	}
  }
  return;
}

void add_adjust_map(){
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
	  temp_map[i][j] = max(0, temp_map[i][j] + adjust_map[i][j]);
	}
  }
  return;
}

void generate_wind(){
  queue<pair<int, int>> q1;
  queue<pair<int, int>> q2;
  queue<pair<int, int>> q3;
  queue<pair<int, int>> q4;

  // 1 (오른쪽)
  for(int i=0; i<right_fan.size(); i++){ // 오른쪽으로 바람
    memset(add_map, 0, sizeof(add_map));
    int fan_r = right_fan[i].first;
	int fan_c = right_fan[i].second;
    int five_r = fan_r;
	int five_c = fan_c + 1;

	if(five_c > C)
	  continue;
	if(wall_map[fan_r][fan_c][1] || wall_map[five_r][five_c][2])
	  continue;

	// wind 5
	add_map[five_r][five_c] += 5;

	// wind 4
	q4.push(make_pair(five_r, five_c));
	while(!q4.empty()){
	  int cur_r = q4.front().first;
	  int cur_c = q4.front().second;
	  q4.pop();

	  for(int k=0; k<3; k++){
	    int tmp_r = cur_r + dw[k];
		int tmp_c = cur_c + 1;

		if(tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
		  continue;
		if(add_map[tmp_r][tmp_c])
		  continue;
		
		if(k == 0){ // dw[k]: -1 
		  if(wall_map[cur_r][cur_c][3] || wall_map[cur_r-1][cur_c][1])
		    continue;
		}
		else if(k == 1){ // dw[k]: 0
		  if(wall_map[cur_r][cur_c][1])
		    continue;
		}
		else if(k == 2){ // dw[k]: 1
		  if(wall_map[cur_r][cur_c][4] || wall_map[cur_r+1][cur_c][1])
		    continue;
		}

		add_map[tmp_r][tmp_c] += 4;
		q3.push(make_pair(tmp_r, tmp_c));
	  }
	}

	// wind 3
	while(!q3.empty()){
	  int cur_r = q3.front().first;
	  int cur_c = q3.front().second;
	  q3.pop();

	  for (int k = 0; k < 3; k++) {
		  int tmp_r = cur_r + dw[k];
		  int tmp_c = cur_c + 1;

		  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
			  continue;
		  if (add_map[tmp_r][tmp_c])
			  continue;

		  if (k == 0) { // dw[k]: -1 
			  if (wall_map[cur_r][cur_c][3] || wall_map[cur_r - 1][cur_c][1])
				  continue;
		  }
		  else if (k == 1) { // dw[k]: 0
			  if (wall_map[cur_r][cur_c][1])
				  continue;
		  }
		  else if (k == 2) { // dw[k]: 1
			  if (wall_map[cur_r][cur_c][4] || wall_map[cur_r + 1][cur_c][1])
				  continue;
		  }

		  add_map[tmp_r][tmp_c] += 3;
		  q2.push(make_pair(tmp_r, tmp_c));
	  }
	}

	// wind 2
	while (!q2.empty()) {
		int cur_r = q2.front().first;
		int cur_c = q2.front().second;
		q2.pop();

		for (int k = 0; k < 3; k++) {
			int tmp_r = cur_r + dw[k];
			int tmp_c = cur_c + 1;

			if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				continue;
			if (add_map[tmp_r][tmp_c])
				continue;

			if (k == 0) { // dw[k]: -1 
				if (wall_map[cur_r][cur_c][3] || wall_map[cur_r - 1][cur_c][1])
					continue;
			}
			else if (k == 1) { // dw[k]: 0
				if (wall_map[cur_r][cur_c][1])
					continue;
			}
			else if (k == 2) { // dw[k]: 1
				if (wall_map[cur_r][cur_c][4] || wall_map[cur_r + 1][cur_c][1])
					continue;
			}

			add_map[tmp_r][tmp_c] += 2;
			q1.push(make_pair(tmp_r, tmp_c));
		}
	}

	// wind 1
	while (!q1.empty()) {
		int cur_r = q1.front().first;
		int cur_c = q1.front().second;
		q1.pop();

		for (int k = 0; k < 3; k++) {
			int tmp_r = cur_r + dw[k];
			int tmp_c = cur_c + 1;

			if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				continue;
			if (add_map[tmp_r][tmp_c])
				continue;

			if (k == 0) { // dw[k]: -1 
				if (wall_map[cur_r][cur_c][3] || wall_map[cur_r - 1][cur_c][1])
					continue;
			}
			else if (k == 1) { // dw[k]: 0
				if (wall_map[cur_r][cur_c][1])
					continue;
			}
			else if (k == 2) { // dw[k]: 1
				if (wall_map[cur_r][cur_c][4] || wall_map[cur_r + 1][cur_c][1])
					continue;
			}

			add_map[tmp_r][tmp_c] += 1;
		}
	}

	add_temp_map();
  }

  // 2 (왼쪽)
  for(int i=0; i<left_fan.size(); i++) { // 왼쪽으로 바람
	  memset(add_map, 0, sizeof(add_map));
	  int fan_r = left_fan[i].first;
	  int fan_c = left_fan[i].second;
	  int five_r = left_fan[i].first;
	  int five_c = left_fan[i].second - 1;

	  if (five_c <= 0)
		  continue;
	  if (wall_map[fan_r][fan_c][2] || wall_map[five_r][five_c][1])
		  continue;

	  // wind 5
	  add_map[five_r][five_c] += 5;

	  // wind 4
	  q4.push(make_pair(five_r, five_c));
	  while (!q4.empty()) {
		  int cur_r = q4.front().first;
		  int cur_c = q4.front().second;
		  q4.pop();

		  for (int k=0; k<3; k++) {
			  int tmp_r = cur_r + dw[k];
			  int tmp_c = cur_c - 1;

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][3] || wall_map[cur_r-1][cur_c][2])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][2])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][4] || wall_map[cur_r+1][cur_c][2])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 4;
			  q3.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 3
	  while (!q3.empty()) {
		  int cur_r = q3.front().first;
		  int cur_c = q3.front().second;
		  q3.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + dw[k];
			  int tmp_c = cur_c - 1;

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][3] || wall_map[cur_r-1][cur_c][2])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][2])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][4] || wall_map[cur_r+1][cur_c][2])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 3;
			  q2.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 2
	  while (!q2.empty()) {
		  int cur_r = q2.front().first;
		  int cur_c = q2.front().second;
		  q2.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + dw[k];
			  int tmp_c = cur_c - 1;

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][3] || wall_map[cur_r - 1][cur_c][2])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][2])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][4] || wall_map[cur_r + 1][cur_c][2])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 2;
			  q1.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 1
	  while (!q1.empty()) {
		  int cur_r = q1.front().first;
		  int cur_c = q1.front().second;
		  q1.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + dw[k];
			  int tmp_c = cur_c - 1;

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][3] || wall_map[cur_r - 1][cur_c][2])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][2])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][4] || wall_map[cur_r + 1][cur_c][2])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 1;
		  }
	  }

	  add_temp_map();
  }

  // 3 (위쪽)
  for(int i=0; i<up_fan.size(); i++) { // 위쪽으로 바람
	  memset(add_map, 0, sizeof(add_map));
	  int fan_r = up_fan[i].first;
	  int fan_c = up_fan[i].second;
	  int five_r = up_fan[i].first - 1;
	  int five_c = up_fan[i].second;

	  if (five_r <= 0)
		  continue;
	  if (wall_map[fan_r][fan_c][3])
		  continue;

	  // wind 5
	  add_map[five_r][five_c] += 5;

	  // wind 4
	  q4.push(make_pair(five_r, five_c));
	  while (!q4.empty()) {
		  int cur_r = q4.front().first;
		  int cur_c = q4.front().second;
		  q4.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r - 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c-1][3])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][3])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c+1][3])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 4;
			  q3.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 3
	  while (!q3.empty()) {
		  int cur_r = q3.front().first;
		  int cur_c = q3.front().second;
		  q3.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r - 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c-1][3])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][3])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c+1][3])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 3;
			  q2.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 2
	  while (!q2.empty()) {
		  int cur_r = q2.front().first;
		  int cur_c = q2.front().second;
		  q2.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r - 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c-1][3])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][3])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c+1][3])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 2;
			  q1.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 1
	  while (!q1.empty()) {
		  int cur_r = q1.front().first;
		  int cur_c = q1.front().second;
		  q1.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r - 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c-1][3])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][3])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c+1][3])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 1;
		  }
	  }
	  
	  add_temp_map();
  }

  // 4 (아래쪽)
  for (int i=0; i<down_fan.size(); i++) { // 아래쪽으로 바람
	  memset(add_map, 0, sizeof(add_map));
	  int fan_r = down_fan[i].first;
	  int fan_c = down_fan[i].second;
	  int five_r = down_fan[i].first+1;
	  int five_c = down_fan[i].second;

	  if (five_r > R)
		  continue;
	  if (wall_map[fan_r][fan_c][4])
		  continue;

	  // wind 5
	  add_map[five_r][five_c] += 5;

	  // wind 4
	  q4.push(make_pair(five_r, five_c));
	  while (!q4.empty()) {
		  int cur_r = q4.front().first;
		  int cur_c = q4.front().second;
		  q4.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c - 1][4])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][4])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c + 1][4])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 4;
			  q3.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 3
	  while (!q3.empty()) {
		  int cur_r = q3.front().first;
		  int cur_c = q3.front().second;
		  q3.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c - 1][4])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][4])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c + 1][4])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 3;
			  q2.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 2
	  while (!q2.empty()) {
		  int cur_r = q2.front().first;
		  int cur_c = q2.front().second;
		  q2.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c - 1][4])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][4])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c + 1][4])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 2;
			  q1.push(make_pair(tmp_r, tmp_c));
		  }
	  }

	  // wind 1
	  while (!q1.empty()) {
		  int cur_r = q1.front().first;
		  int cur_c = q1.front().second;
		  q1.pop();

		  for (int k = 0; k < 3; k++) {
			  int tmp_r = cur_r + 1;
			  int tmp_c = cur_c + dw[k];

			  if (tmp_r <= 0 || tmp_r > R || tmp_c <= 0 || tmp_c > C)
				  continue;
			  if (add_map[tmp_r][tmp_c])
				  continue;

			  if (k == 0) { // dw[k]: -1 
				  if (wall_map[cur_r][cur_c][2] || wall_map[cur_r][cur_c-1][4])
					  continue;
			  }
			  else if (k == 1) { // dw[k]: 0
				  if (wall_map[cur_r][cur_c][4])
					  continue;
			  }
			  else if (k == 2) { // dw[k]: 1
				  if (wall_map[cur_r][cur_c][1] || wall_map[cur_r][cur_c+1][4])
					  continue;
			  }

			  add_map[tmp_r][tmp_c] += 1;
		  }
	  }

	  add_temp_map();
  }


 return;
}

void adjust_temp(){
  memset(adjust_map, 0, sizeof(adjust_map));
  bool adjust_check[25][25][5] = {0}; // 1(오른쪽)c++, 2(왼쪽)c--, 3(위쪽)r--, 4(아래쪽)r++

  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
		int cur_r = i;
		int cur_c = j;

		for (int t=0; t<4; t++) {
			int tar_r = cur_r + dx[t]; // {-1, 1, 0, 0};
			int tar_c = cur_c + dy[t]; // {0, 0, -1, 1};

			if (tar_r <= 0 || tar_r > R || tar_c <= 0 || tar_c > C)
				continue;

			if (t == 0 && wall_map[cur_r][cur_c][3])  // 위쪽
				continue;
			else if (t == 1 && wall_map[cur_r][cur_c][4])  // 아래쪽
				continue;
			else if (t == 2 && wall_map[cur_r][cur_c][2])  // 왼쪽
				continue;
			else if (t == 3 && wall_map[cur_r][cur_c][1])  // 오른쪽
				continue;

			if (t == 0){ // 위쪽
			  if(adjust_check[cur_r][cur_c][3])
			    continue;
			  else {
			    adjust_check[cur_r][cur_c][3] = 1;
				adjust_check[tar_r][tar_c][4] = 1;
			  }
			}
			else if (t == 1) { // 아래쪽
			  if (adjust_check[cur_r][cur_c][4])
			    continue;
			  else {
			    adjust_check[cur_r][cur_c][4] = 1;
				adjust_check[tar_r][tar_c][3] = 1;
			  }
			}
			else if (t == 2) { // 왼쪽
				if (adjust_check[cur_r][cur_c][2])
					continue;
				else {
					adjust_check[cur_r][cur_c][2] = 1;
					adjust_check[tar_r][tar_c][1] = 1;
				}
			}
			else if (t == 3) { // 오른쪽
				if (adjust_check[cur_r][cur_c][1])
					continue;
				else {
					adjust_check[cur_r][cur_c][1] = 1;
					adjust_check[tar_r][tar_c][2] = 1;
				}
			}
  
			int cur_temp = temp_map[cur_r][cur_c];
			int tar_temp = temp_map[tar_r][tar_c];
			int temp_dis = abs(cur_temp - tar_temp);
			int move_temp = temp_dis / 4;

			int after_cur_temp = 0;
			int after_tar_temp = 0;

			if (cur_temp > tar_temp) { // cur_temp -> tar_temp로 온도옮김
				after_cur_temp = -move_temp;
				after_tar_temp = move_temp;
			}
			else if (cur_temp < tar_temp) { // tar_temp -> cur_temp로 온도옮김
			    after_cur_temp = move_temp;
				after_tar_temp = -move_temp;
			}

			adjust_map[cur_r][cur_c] += after_cur_temp;
			adjust_map[tar_r][tar_c] += after_tar_temp;
		}
	}
  }

  add_adjust_map();
  return;
}

void reduce_temp(){
 for(int i=1; i<=C; i++){
   if(temp_map[1][i] >= 1)
     temp_map[1][i]--;
   if(temp_map[R][i] >= 1)
     temp_map[R][i]--;
 }

 for(int i=2; i<=R-1; i++){
   if(temp_map[i][1] >= 1)
     temp_map[i][1]--;
   if(temp_map[i][C] >= 1)
     temp_map[i][C]--;
 }

  return;
}

bool check_temperature(){
  for(int i=0; i<investigate_space.size(); i++){
    int tmp_r = investigate_space[i].first;
	int tmp_c = investigate_space[i].second;

	if(temp_map[tmp_r][tmp_c] < K)
	  return false;
  }

  return true;
}

void solve(){
  while(true){
    // 1. 온풍기에서 바람이 한 번 나옴
	generate_wind();

	// 2. 온도가 조절됨.
	adjust_temp();

	// 3. 온도가 1이상인 가장 바깥쪽 칸의 온도가 1씩 감소
	reduce_temp();

	// 4. 초콜릿을 하나 먹는다.
	eaten_chocolate++;

	if (eaten_chocolate == 101)
		break;

	// 5. 조사하는 모든 칸의 온도가 K 이상이 되었는지 검사.
	if(check_temperature())
	  break;
  }

  printf("%d\n", eaten_chocolate);
  return;
}

int main(){
  scanf("%d %d %d", &R, &C, &K);
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
	  scanf("%d", &map[i][j]);

	  if(map[i][j] == 1)
	    right_fan.push_back(make_pair(i,j));
	  else if(map[i][j] == 2)
	    left_fan.push_back(make_pair(i,j));
	  else if(map[i][j] == 3)
	    up_fan.push_back(make_pair(i,j));
	  else if(map[i][j] == 4)
	    down_fan.push_back(make_pair(i,j));
	  else if(map[i][j] == 5)
	    investigate_space.push_back(make_pair(i,j));
	}
  }

  int x, y, t;
  memset(wall_map, 0, sizeof(wall_map));
  scanf("%d", &W);
  for(int i=0; i<W; i++){
    scanf("%d %d %d", &x, &y, &t);
	walls.push_back(make_pair(make_pair(x,y), t));

	if(t==0) { // x,y와 x-1,y 사이에 벽
	  int r1 = x;
	  int c1 = y;

	  int r2 = x-1;
	  int c2 = y;

	  wall_map[r1][c1][3] = 1;
	  
	  if(r2 >= 1)
	    wall_map[r2][c2][4] = 1;
	}
	else if(t==1) { // x,y와 x,y+1 사이에 벽
	  int r1 = x;
	  int c1 = y;

	  int r2 = x;
	  int c2 = y+1;

	  wall_map[r1][c1][1] = 1;

	  if(c2 <= C)
	    wall_map[r2][c2][2] = 1;
	}
  }

  solve();
  return 0;
}
