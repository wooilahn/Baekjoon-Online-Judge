#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int c_arr[105] = {0};

vector<pair<int, pair<int,int>>> v;

int main(){

  int n;
  scanf("%d", &n);

  int country, sno, score;
  for(int i=0; i<n; i++){
    scanf("%d %d %d", &country, &sno, &score);
	v.push_back(make_pair(-score, make_pair(country, sno)));
  }

  sort(v.begin(), v.end());
  int cnt = 0;

  for(int i=0; i<n; i++){
    if(cnt >= 3)
	  break;

    int cur_country = v[i].second.first;

	if(c_arr[cur_country] < 2){
	  c_arr[cur_country]++;
	  printf("%d %d\n", v[i].second.first, v[i].second.second);
	  cnt++;
	}
  }


  return 0;
}
