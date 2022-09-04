#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int,int>, pair<int,int>>> v;

int main(){
  int N, K;
  scanf("%d %d", &N, &K);

  int country, g, s, b;
  int t_g, t_s, t_b;

  for(int i=0; i<N; i++){
    scanf("%d %d %d %d", &country, &g, &s, &b);

	if(country == K){
	  t_g = g;
	  t_s = s;
	  t_b = b;
	}

	v.push_back(make_pair(make_pair(g, s), make_pair(b, country)));
  }

  sort(v.begin(), v.end());

  for(int i=N-1; i>=0; i--){
    if(t_g == v[i].first.first && t_s == v[i].first.second && t_b == v[i].second.first){
	  printf("%d\n", (N-1)-i+1);
	  break;
	}
  }

  return 0;
}
