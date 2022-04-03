#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> gas_station; // <dist, gas>
priority_queue<int> max_heap;

int main(){
  int N;
  scanf("%d", &N);

  int dist, gas;

  for(int i=0; i<N; i++){
    scanf("%d %d", &dist, &gas);
	gas_station.push_back(make_pair(dist, gas));
  }

  sort(gas_station.begin(), gas_station.end());

  int tar_dist, cur_gas;
  scanf("%d %d", &tar_dist, &cur_gas);

  int cur_dist = cur_gas;
  cur_gas = 0;
  int idx = 0;

  bool goal_flag = true;
  int ans = 0;

  for(;cur_dist < tar_dist;){
    if(idx < N){
	  while(gas_station[idx].first <= cur_dist){
	    max_heap.push(gas_station[idx].second);
	    idx++;

		if(idx == N)
		  break;
	  }
	}
	
	if (max_heap.empty()) {
		goal_flag = false;
		break;
	}

	cur_dist += max_heap.top();
	max_heap.pop();
	ans++;
  }

  if(!goal_flag)
    printf("-1\n");
  else if(goal_flag)
    printf("%d\n", ans);

  return 0;
}
