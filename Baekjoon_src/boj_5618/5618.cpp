#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[4] = {0};
vector<int> ans;

int gcd(int n1, int n2){
  while(n2 != 0){
    int tmp = n1 % n2;
	n1 = n2;
	n2 = tmp;
  }

  return n1;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &arr[i]);

  int g = gcd(arr[0], gcd(arr[1], arr[2]));

  for(int k=1; k*k<=g; k++){
    if(k*k == g)
	  ans.push_back(k);
    else if(g%k == 0){
	  ans.push_back(k);
	  ans.push_back(g/k);
	}
  }

  sort(ans.begin(), ans.end());

  for(int idx=0; idx<ans.size(); idx++)
    printf("%d\n", ans[idx]);

  return 0;
}
