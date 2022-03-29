#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

int main(){

  for(int i=1; i<=8; i++){
    int score;
	scanf("%d", &score);

	v.push_back(make_pair(-score, i));
  }

  sort(v.begin(), v.end());

  int total_score = 0;
  vector<int> p_num;

  for(int i=0; i<5; i++) {
    total_score += -v[i].first;
	p_num.push_back(v[i].second);
  }

  sort(p_num.begin(), p_num.end());
  
  printf("%d\n", total_score);

  for(int i=0; i<5; i++)
    printf("%d ", p_num[i]);
  printf("\n");
  
  return 0;
}
