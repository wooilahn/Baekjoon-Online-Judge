#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(){
  int t;
  scanf("%d", &t);

  int n, num;

  while(t--){
	scanf("%d", &n);
	v.clear();

	for(int i=0; i<n; i++){
	  scanf("%d", &num);
	  v.push_back(num);
	}

	sort(v.begin(), v.end());

	printf("%d\n", (v[n-1] - v[0])*2);
  }

  return 0;
}
