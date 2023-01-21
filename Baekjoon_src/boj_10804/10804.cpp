#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
  for(int i=1; i<=20; i++)
    v.push_back(i);

  int a, b;
  for(int i=0; i<10; i++){
    scanf("%d %d", &a, &b);
	reverse(v.begin()+a-1, v.begin()+b);
  }

  for(int i=0; i<v.size(); i++)
    printf("%d ", v[i]);
  printf("\n");

  return 0;
}
