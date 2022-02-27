#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int map[55][55] = {0};
vector<pair<int,int>> house;
vector<pair<int,int>> store;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &map[i][j]);

	  if(map[i][j] == 1)
	    house.push_back(make_pair(i,j));
	  else if(map[i][j] == 2)
	    store.push_back(make_pair(i,j));
	}
  }

  vector<int> v_c(store.size());
  int v_size = v_c.size();

  for(int i=0; i<M; i++){
    v_c[v_size-i-1] = 1;
  }

  int ans = 999999999;

  do {
    vector<int> ch;
	ch.clear();

	for(int i=0; i<v_c.size(); i++){
	  if(v_c[i] == 0)
	    continue;
	  else if(v_c[i] == 1)
	    ch.push_back(i);
	}

	int tmp_ans = 0;

	for(int i=0; i<house.size(); i++){
	  int cur_x = house[i].first;
	  int cur_y = house[i].second;
	  int cur_d = 9999999;

	  for(int k=0; k<ch.size(); k++){
	    int tar_x = store[ch[k]].first;
		int tar_y = store[ch[k]].second;

		cur_d = min(cur_d, abs(cur_x - tar_x) + abs(cur_y - tar_y));
	  }

	  tmp_ans += cur_d;
	}

	ans = min(ans, tmp_ans);
    
  } while(next_permutation(v_c.begin(), v_c.end()));

  printf("%d\n", ans);
  return 0;
}
