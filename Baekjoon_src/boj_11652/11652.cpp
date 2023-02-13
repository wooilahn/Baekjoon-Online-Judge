#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<ll> v;

int main(){
  ll N;
  scanf("%lld", &N);

  ll num;

  for(ll i=0; i<N; i++){
    scanf("%lld", &num);
	v.push_back(num);
  }

  sort(v.begin(), v.end());

  bool find_flag = true;
  ll cur_idx = 1;
  ll cur_val = v[0];
  ll ans_cnt = 1;
  ll ans = v[0];

  for(ll i=cur_idx; i<N; i++){
    if(cur_val == v[i]){
	  ans_cnt++;
	}
	else{
	  find_flag = false;
	  break;
	}

	cur_idx++;
  }

  ll tmp_cnt = 0;

  for(ll i=cur_idx; i<N; i++){
    if(find_flag == false){
	  cur_val = v[i];
	  tmp_cnt = 1;
	  find_flag = true;
	  continue;
	}

	if(cur_val == v[i]){
	  tmp_cnt++;
	}
	else {
	  if(ans_cnt < tmp_cnt){
	    ans = cur_val;
		ans_cnt = tmp_cnt;
	  }

	  cur_val = v[i];
	  tmp_cnt = 1;
	  find_flag = true;
	}
  }

  if(ans_cnt < tmp_cnt)
    ans = cur_val;

  printf("%lld\n", ans);

  return 0;
}
