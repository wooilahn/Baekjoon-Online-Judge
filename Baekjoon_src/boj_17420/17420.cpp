#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;
typedef long long ll;

priority_queue<pair<ll, ll>> pq;
ll A[100005] = {0};
ll B[100005] = {0};

int main(){
  int N;
  ll ans = 0;
  scanf("%d", &N);

  for(int i=1; i<=N; i++)
    scanf("%lld", &A[i]);

  for(int i=1; i<=N; i++)
    scanf("%lld", &B[i]);
  
  for(int i=1; i<=N; i++)
    pq.push(make_pair(-B[i], -A[i]));

  ll prev_max_use_d = -1;
  ll cur_max_use_d = -1;

  for(int i=1; i<=N; i++){
    ll cur_B = -pq.top().first;
	ll cur_A = -pq.top().second;
	pq.pop();

	ll limit_use_d;

	if(prev_max_use_d < cur_B)
	  limit_use_d = cur_B;
	else
	  limit_use_d = prev_max_use_d;

	if(limit_use_d > cur_A){
	  ll q = ((limit_use_d-cur_A)+29) / 30;
	  cur_A += q*30;
	  ans += q;
	}

	cur_max_use_d = max(cur_max_use_d, cur_A);

	if(i != N && cur_B != -pq.top().first)
	  prev_max_use_d = cur_max_use_d;
  }

  printf("%lld\n", ans);

  return 0;
}
