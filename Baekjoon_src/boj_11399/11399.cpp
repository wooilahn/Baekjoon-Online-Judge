#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int p;
	
	for(int i=0; i<n; i++){
		scanf("%d",&p);
		v.push_back(p);
	}
	
	sort(v.begin(), v.end());
	
	int ans[1005] = {0};
	int sum = 0;
	
	ans[0] = v.at(0);
	sum += ans[0];
	
	for(int i=1; i<n; i++){
		ans[i] = ans[i-1] + v.at(i);
		sum += ans[i];
	}
	
	printf("%d\n", sum);
	return 0;
}
