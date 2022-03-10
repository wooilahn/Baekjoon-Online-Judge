#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[15][15] = {0};
vector<int> chess[15][15];
vector<pair<pair<int, int>, int>> knight;

int main(){
  int N, K;
  scanf("%d %d", &N, &K);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);
	}
  }

  int r, c, dir;

  for(int i=0; i<K; i++){
    scanf("%d %d %d", &r, &c, &dir);
	knight.push_back(make_pair(make_pair(r-1,c-1), dir)); // 0 ~ K-1 idx
	chess[r-1][c-1].push_back(i); // 0 ~ K-1 idx가 넣어짐
  }

  int turn = 0;

  while(turn <= 1000){
	  for (int i = 0; i < knight.size(); i++) {
		  int cur_r = knight[i].first.first;
		  int cur_c = knight[i].first.second;
		  int cur_dir = knight[i].second; // 1: right, 2: left, 3: up, 4: down

		  int k_idx = -1;
		  for (int k = 0; k < chess[cur_r][cur_c].size(); k++) {
			  if (chess[cur_r][cur_c].at(k) == i) {
				  k_idx = k;
				  break;
			  }
		  }

		  if (cur_dir == 1) { // 1: right (cur_c + 1)
			  if (cur_c + 1 >= N) { // chess를 벗어나는 경우
				  cur_dir = 2;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 2;

				  if (map[cur_r][cur_c - 1] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r][cur_c - 1] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r][cur_c + 1] == 2) {
				  cur_dir = 2;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 2;

				  if (cur_c - 1 < 0)
					  ;
				  else if (map[cur_r][cur_c - 1] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r][cur_c - 1] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r][cur_c + 1] == 0) {
				  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
					  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
			  else if (map[cur_r][cur_c + 1] == 1) {
				  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
					  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
		  }
		  else if (cur_dir == 2) {  // 2: left (cur_c - 1)
			  if (cur_c - 1 < 0) { // chess를 벗어나는 경우
				  cur_dir = 1;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 1;

				  if (map[cur_r][cur_c + 1] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r][cur_c + 1] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r][cur_c - 1] == 2) {
				  cur_dir = 1;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 1;

				  if (cur_c + 1 >= N)
					  ;
				  else if (map[cur_r][cur_c + 1] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r][cur_c + 1] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r][cur_c + 1].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r][cur_c - 1] == 0) {
				  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
					  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
			  else if (map[cur_r][cur_c - 1] == 1) {
				  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
					  chess[cur_r][cur_c - 1].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.second = cur_c - 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
		  }
		  else if (cur_dir == 3) {  // 3: up (cur_r - 1)
			  if (cur_r - 1 < 0) { // chess를 벗어나는 경우
				  cur_dir = 4;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 4;

				  if (map[cur_r + 1][cur_c] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r + 1][cur_c] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r - 1][cur_c] == 2) {
				  cur_dir = 4;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 4;

				  if (cur_r + 1 >= N)
					  ;
				  else if (map[cur_r + 1][cur_c] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r + 1][cur_c] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r - 1][cur_c] == 0) {
				  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
					  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
			  else if (map[cur_r - 1][cur_c] == 1) {
				  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
					  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
		  }
		  else if (cur_dir == 4) {  // 4: down (cur_r + 1)
			  if (cur_r + 1 >= N) { // chess를 벗어나는 경우
				  cur_dir = 3;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 3;

				  if (map[cur_r - 1][cur_c] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r - 1][cur_c] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r + 1][cur_c] == 2) {
				  cur_dir = 3;
				  knight[chess[cur_r][cur_c].at(k_idx)].second = 3;

				  if (cur_r - 1 < 0)
					  ;
				  else if (map[cur_r - 1][cur_c] == 0) {
					  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
						  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
				  else if (map[cur_r - 1][cur_c] == 1) {
					  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
						  chess[cur_r - 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
						  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r - 1;
					  }
					  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
				  }
			  }
			  else if (map[cur_r + 1][cur_c] == 0) {
				  for (int k = k_idx; k < chess[cur_r][cur_c].size(); k++) {
					  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
			  else if (map[cur_r + 1][cur_c] == 1) {
				  for (int k = chess[cur_r][cur_c].size() - 1; k >= k_idx; k--) {
					  chess[cur_r + 1][cur_c].push_back(chess[cur_r][cur_c].at(k));
					  knight[chess[cur_r][cur_c].at(k)].first.first = cur_r + 1;
				  }
				  chess[cur_r][cur_c].erase(chess[cur_r][cur_c].begin() + k_idx, chess[cur_r][cur_c].end());
			  }
		  }

		  // knight vector를 순회하며 size가 4를 넘는게 있는지 check
		  for (int k = 0; k < knight.size(); k++) {
			  int k_r = knight[k].first.first;
			  int k_c = knight[k].first.second;

			  if (chess[k_r][k_c].size() >= 4){
			    printf("%d\n", turn+1);
				return 0;
			  }
		  }
	  }

	  turn++;
  }

  if(turn > 1000)
    printf("-1\n");

  return 0;
}
