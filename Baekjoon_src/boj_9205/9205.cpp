#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

vector<pair<int, int>> store;
vector<int> check;

int main(){
  int t, n;
  scanf("%d", &t);

  while(t--){
    queue<pair<pair<int,int>, int>> q;
    bool finish_flag = false;

    scanf("%d", &n);
	check.clear();
	check.resize(n);

	int s_x, s_y;
	scanf("%d %d", &s_x, &s_y);
	q.push(make_pair(make_pair(s_x, s_y), -1));

	store.clear();
	int st_x, st_y;
	for(int i=0; i<n; i++){
	  scanf("%d %d", &st_x, &st_y);
	  store.push_back(make_pair(st_x, st_y));
	}

	int d_x, d_y;
	scanf("%d %d", &d_x, &d_y);

	while(!q.empty()){
	  int cur_x = q.front().first.first;
	  int cur_y = q.front().first.second;
	  int cur_idx = q.front().second;
	  q.pop();

	  int finish_dist = abs(cur_x - d_x) + abs(cur_y - d_y);

	  if(finish_dist <= 1000){
	    finish_flag = true;
		break;
	  }

	  if(cur_idx != -1){
	    if(check[cur_idx] == 1)
		  continue;
		else
		  check[cur_idx] = 1;
	  }

	  for(int i=0; i<n; i++){
	    int tmp_x = store[i].first;
		int tmp_y = store[i].second;
		int tmp_idx = i;

		if(check[tmp_idx])
		  continue;

		int dist = abs(cur_x - tmp_x) + abs(cur_y - tmp_y);

		if(dist <= 1000)
		  q.push(make_pair(make_pair(tmp_x, tmp_y), tmp_idx));
	  }
	}

	if(finish_flag)
	  printf("happy\n");
	else
	  printf("sad\n");
  }

  return 0;
}
