#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main(){
  int num;
  int sum = 0;

  for(int i=0; i<5; i++){
    scanf("%d", &num);
	v.push_back(num);
	sum += num;
  }

  sort(v.begin(), v.end());
  printf("%d\n%d\n", sum/5, v[2]);

  return 0;
}
