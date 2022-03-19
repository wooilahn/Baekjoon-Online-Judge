#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
bool check[2005] = {0};
vector<int> v;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    int num;
    scanf("%d", &num);

    if(check[1000-num])
      continue;
    
    check[1000-num] = true;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
