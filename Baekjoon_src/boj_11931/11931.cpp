#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
  int N;
  scanf("%d", &N);

  int num;
  for(int i=0; i<N; i++){
    scanf("%d", &num);
	v.push_back(num);
  }

  sort(v.begin(), v.end());

  for(int i=v.size()-1; i>=0; i--)
    printf("%d\n", v[i]);

  return 0;
}
