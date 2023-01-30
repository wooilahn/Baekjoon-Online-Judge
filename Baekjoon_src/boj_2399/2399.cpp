#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  vector<long long> v;

  long long num;
  for(int i=0; i<n; i++){
    scanf("%lld", &num);
	v.push_back(num);
  }

  sort(v.begin(), v.end());

  long long ans = 0;

  for(int i=v.size()-1; i>=1; i--){
    for(int j=i-1; j>=0; j--){
	  ans += v[i] - v[j];
	}
  }

  printf("%lld\n", ans*2);
  return 0;
}
