#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;

int main(){
  int num;

  for(int i=0; i<10; i++){
    scanf("%d", &num);
	v1.push_back(num);
  }

  for(int i=0; i<10; i++){
    scanf("%d", &num);
	v2.push_back(num);
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  printf("%d %d\n", v1[7]+v1[8]+v1[9], v2[7]+v2[8]+v2[9]);

  return 0;
}
