#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bag;
vector<pair<int,int>> jew;
priority_queue<int> max_heap;

int main(){
  int N, K;
  scanf("%d %d", &N, &K);

  int weight, price;

  for(int i=0; i<N; i++){
    scanf("%d %d", &weight, &price);
	jew.push_back(make_pair(weight, price));
  }

  sort(jew.begin(), jew.end());

  int b_weight;
  for(int i=0; i<K; i++){
    scanf("%d", &b_weight);
	bag.push_back(b_weight);
  }

  sort(bag.begin(), bag.end());

  long long ans = 0;
  int cur_idx = 0;

  for(int i=0; i<K; i++){
    
	for(;cur_idx<N && bag[i]>=jew[cur_idx].first;){
	  max_heap.push(jew[cur_idx++].second);
	}
    
	if(!max_heap.empty()){
	  ans += (long long)max_heap.top();
	  max_heap.pop();
	}
  }

  printf("%lld\n", ans);

  return 0;
}
